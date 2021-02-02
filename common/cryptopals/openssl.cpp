#include <cassert>
#include <openssl/evp.h>
#include <stdexcept>

#include "cryptopals/openssl.h"
#include "cryptopals/padding.h"

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

std::string xcrypt_aes128_ecb(const std::string &text, const std::string &key,
                              bool encrypt)
{
    assert(key.size() == 16);
    auto *ctx = EVP_CIPHER_CTX_new();
    if (!ctx)
        throw std::runtime_error("new");
    if (!EVP_CipherInit_ex(ctx, EVP_aes_128_ecb(), nullptr, uchar(key), nullptr,
                           encrypt))
        throw std::runtime_error("init");

    std::string xcrypted_text(text.size() + EVP_CIPHER_CTX_block_size(ctx), 0);
    int outlen, tmplen;
    if (!EVP_CipherUpdate(ctx, uchar(xcrypted_text), &outlen, uchar(text),
                          text.size()))
        throw std::runtime_error("update");
    if (!EVP_CipherFinal_ex(ctx, uchar(xcrypted_text) + outlen, &tmplen))
        throw std::runtime_error("final");
    EVP_CIPHER_CTX_free(ctx);

    // remove padding/unwritten bytes
    return xcrypted_text.substr(0, outlen + tmplen);
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

} // namespace cryptopals
