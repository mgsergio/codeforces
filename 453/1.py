import sys

from itertools import cycle, chain

n, m = map(int, sys.stdin.readline().split())

ts = [
    map(int, l.split())
    for l in sys.stdin
]

def join(a, b):
    if a[1] >= b[0]:
        return [a[0], max(b[1], a[1])]
    return b

ts.sort(key=lambda x: [x[0], -x[1]])

res = [[0, 0]]
for s in ts:
    res.append(join(res[-1], s))

for s in filter(lambda x: x[0] == 0, res):
    if m <= s[1]:
        print 'YES'
        exit()

print 'NO'
