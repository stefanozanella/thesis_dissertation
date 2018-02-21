#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

#include "sha256.h"

double get_time()
{
    struct timespec t;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t);
    return t.tv_sec + t.tv_nsec*1e-9;
}

int main() {
  double avg = 0.0;

  uint32_t hash[8];

  for (int j = 0; j < 1; j++) {
    double start = get_time();

    for (int k = 0; k < 10248576; k++) {
      sha256_sse4("1234567890", hash, 8);
    }

    double end = get_time();
    avg += end - start;
  }

  printf("avg: %f\n", avg/10);

  return 0;
}
