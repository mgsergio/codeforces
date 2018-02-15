import sys

from collections import Counter

n = int(sys.stdin.readline())

def max_nines(n):
    m = 9
    i = 0
    while m < n:
        m  = m * 10 + 9
        i += 1
    return i

max_n = n + n - 1
nines = max_nines(max_n)
p = 10 ** nines

all_nines = int(('9' * nines) or '0')
d = Counter()
for i in xrange(1, n + 1):
    d[i % p] += 1

pairs = 0
for i in xrange(1, n + 1):
    pairs += d[all_nines - i % p]

print pairs / 2
