add_challenge(1
  ARGS  "YELLOW SUBMARINE" 20
  OUTPUT_FILE ${PROJECT_SOURCE_DIR}/challenge-data/2.1-padded.txt
)
add_challenge(2_pre0
  ARGS "an input string" "key has 16 bytes"
  OUTPUT "an input string"
)
add_challenge(2
  ARGS ${PROJECT_SOURCE_DIR}/challenge-data/10.txt "YELLOW SUBMARINE"
  OUTPUT_FILE ${PROJECT_SOURCE_DIR}/challenge-data/stayin-alive.txt
)
