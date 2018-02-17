import hashlib
import time
import random

iterations = 10
key_lengths = range(80,256+1)

for key_length in key_lengths:
    total = 0
    for _ in range(0, iterations):
        key = str(random.getrandbits(key_length)).encode('utf-8')
        start = time.time()
        for _ in range(2**20):
            hashlib.sha256(key).hexdigest()
        end = time.time()
        total += end - start
    print(key_length, total/iterations)
