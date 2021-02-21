#include <cassert>
#include <memory>
#include <openssl/evp.h>
#include <stdexcept>

#include "cryptopals/openssl.h"
#include "cryptopals/padding.h"
#include "cryptopals/string_utils.h"
#include "cryptopals/xor.h"

namespace cryptopals
{

const unsigned char *uchar(const std::string &s)
{
    return reinterpret_cast<const unsigned char *>(s.data());
}

unsigned char *uchar(std::string &s)
{
    return reinterpret_cast<unsigned char *>(s.data());
}

class EVP_CIPHER_CTX_deleter {
  public:
    void operator()(EVP_CIPHER_CTX *ctx) { EVP_CIPHER_CTX_free(ctx); }
};

class Cipher {
  public:
    Cipher()
    {
        m_ctx.reset(EVP_CIPHER_CTX_new());
        if (!m_ctx)
        {
            throw std::runtime_error("new");
        }
    }

    unsigned int block_size() { return EVP_CIPHER_CTX_block_size(ctx()); }

    void set_padding(bool padding)
    {
        if (EVP_CIPHER_CTX_set_padding(ctx(), padding) != 1)
        {
            throw std::runtime_error("cipher set padding failed");
        }
    };

    int update(const std::string &in, unsigned char *out)
    {
        int len;
        if (EVP_CipherUpdate(ctx(), out, &len, uchar(in), in.size()) != 1)
            throw std::runtime_error("cipher update failed");
        return len;
    }

    int update(const std::string &in, std::string &out)
    {
        return update(in, uchar(out));
    }

    int final(unsigned char *out)
    {
        int len;
        if (!EVP_CipherFinal_ex(ctx(), out, &len))
            throw std::runtime_error("cipher final failed");
        return len;
    }

  protected:
    EVP_CIPHER_CTX *ctx() { return m_ctx.get(); }

  private:
    std::unique_ptr<EVP_CIPHER_CTX, EVP_CIPHER_CTX_deleter> m_ctx;
};

class AES128_ECB_Cipher : public Cipher {
  public:
    AES128_ECB_Cipher(const std::string &key, bool encrypt) : Cipher()
    {
        assert(key.size() == 16);
        if (!EVP_CipherInit_ex(ctx(), EVP_aes_128_ecb(), nullptr, uchar(key),
                               nullptr, encrypt))
        {
            throw std::runtime_error("init");
        }
    }
};

std::string xcrypt_aes128_ecb(const std::string &text, const std::string &key,
                              bool encrypt)
{

    AES128_ECB_Cipher cipher(key, encrypt);
    std::string xcrypted_text(text.size() + cipher.block_size(), 0);
    int outlen = 0;
    outlen += cipher.update(text, xcrypted_text);
    outlen += cipher.final(uchar(xcrypted_text) + outlen);

    // remove padding/unwritten bytes
    return xcrypted_text.substr(0, outlen);
}

std::string decrypt_aes128_ecb(const std::string &cipher_text,
                               const std::string &key)
{
    return xcrypt_aes128_ecb(cipher_text, key, false);
}

std::string encrypt_aes128_ecb(const std::string &text, const std::string &key)
{
    return xcrypt_aes128_ecb(text, key, true);
}

std::string decrypt_aes128_cbc(const std::string &cipher_text,
                               const std::string &key, const std::string &iv)
{

    assert(iv.size() == key.size());
    std::string previous_cipherblock = iv;
    std::string decrypted_text;
    int outlen = 0;
    for (const auto &cipher_block : blocks(cipher_text, 16))
    {
        AES128_ECB_Cipher cipher(key, false);
        cipher.set_padding(false);
        std::string decrypted_block(cipher_block.size() + cipher.block_size(),
                                    0);
        auto block_len = cipher.update(cipher_block, decrypted_block);
        block_len += cipher.final(uchar(decrypted_block) + block_len);
        assert(block_len == cipher.block_size());
        auto decrypted_block2 =
            bit_xor(decrypted_block.substr(0, block_len), previous_cipherblock);
        decrypted_text += decrypted_block2;
        previous_cipherblock = cipher_block;
        outlen += block_len;
    }
    return decrypted_text.substr(0, outlen);
}

} // namespace cryptopals
