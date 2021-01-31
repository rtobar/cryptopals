add_challenge(1
  ARGS  49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d
  OUTPUT SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t
)
add_challenge(2
  ARGS 1c0111001f010100061a024b53535009181c 686974207468652062756c6c277320657965
  OUTPUT 746865206b696420646f6e277420706c6179
)
add_challenge(3
  ARGS 1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736
  OUTPUT "key: X, plain text: Cooking MC's like a pound of bacon"
)
add_challenge(4
  ARGS ${PROJECT_SOURCE_DIR}/challenge-data/4.txt
  OUTPUT "key: 5, plain text: Now that the party is jumping"
)
add_challenge(5
  ARGS "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal" ICE
  OUTPUT "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272\na282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f"
)
add_challenge(6_pre0
  ARGS "this is a test" "wokka wokka!!!"
  OUTPUT 37
)
add_challenge(6
  ARGS ${PROJECT_SOURCE_DIR}/challenge-data/6.txt
  OUTPUT_FILE ${PROJECT_SOURCE_DIR}/challenge-data/6-decrypted.txt
)
add_challenge(7
  ARGS ${PROJECT_SOURCE_DIR}/challenge-data/7.txt "YELLOW SUBMARINE"
  OUTPUT_FILE ${PROJECT_SOURCE_DIR}/challenge-data/7-decrypted.txt
)
add_challenge(8
  ARGS ${PROJECT_SOURCE_DIR}/challenge-data/8.txt
  OUTPUT "line: d880619740a8a19b7840a8a31c810a3d08649af70dc06f4fd5d2d69c744cd283e2dd052f6b641dbf9d11b0348542bb5708649af70dc06f4fd5d2d69c744cd2839475c9dfdbc1d46597949d9c7e82bf5a08649af70dc06f4fd5d2d69c744cd28397a93eab8d6aecd566489154789a6b0308649af70dc06f4fd5d2d69c744cd283d403180c98c8f6db1f2a3f9c4040deb0ab51b29933f2c123c58386b06fba186a
block: 08649af70dc06f4fd5d2d69c744cd283"
)
