#include <stdio.h>
#include <openssl/sha.h>
#include <sys/time.h>
#include <sys/resource.h>

double get_time()
{
    struct timespec t;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t);
    return t.tv_sec + t.tv_nsec*1e-9;
}

int main() {
  double avg = 0.0;

  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256_CTX sha256;

  for (int j = 0; j < 10; j++) {
    double start = get_time();

    for (int k = 0; k < 10248576; k++) {
      SHA256_Init(&sha256);
      SHA256_Update(&sha256, "1234567890", 10);
      SHA256_Final(hash, &sha256);
    }

    double end = get_time();
    avg += end - start;
  }

  printf("avg: %f\n", avg/10);

  return 0;
}
