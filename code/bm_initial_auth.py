import hashlib
import time

iterations = 10
chain_lengths = [103680, 414720]#range(20,30+1)

for exp in chain_lengths:
    chain_length = exp #2**exp
    total = 0
    for _ in range(0, iterations):
        start = time.time()
        for _ in range(0, chain_length):
            hashlib.sha256(b"1234567890").hexdigest()
        end = time.time()
        total += end - start
    print(exp, total/iterations)
