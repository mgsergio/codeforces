import sys
from math import sqrt

n = int(sys.stdin.readline())
a = map(int, sys.stdin.readline().split())

m = None
for i in a:
    if i < 0:
        if m is None:
            m = i
        else:
            m = max(m, i)
        continue
    if int(sqrt(i)) ** 2 == i:
        continue
    m = max(m, i)

print m
