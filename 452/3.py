import sys

n = int(sys.stdin.readline())

g = []
ls, rs = 0, 0

for i in xrange(n, 0, -1):
    if ls <= rs:
        g.append(i)
        ls += i
    else:
        rs += i

print abs(ls - rs)
print '{} {}'.format(len(g), ' '.join(map(str, g)))
