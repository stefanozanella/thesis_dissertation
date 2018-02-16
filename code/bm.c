#include <openssl/sha.h>

int main() {
  for (int k = 0; k < 10248576; k++) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, "1234567890", 10);
    SHA256_Final(hash, &sha256);
  }

  return 0;
}
