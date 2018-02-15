import sys

N = 10000000

n = int(sys.stdin.readline())
a = int(sys.stdin.readline())
b = int(sys.stdin.readline())

for x in xrange(0, N + 1):
    d = n - x * a
    if d < 0:
        print 'NO'
        exit()
    elif d % b == 0:
        print 'YES'
        print x, d / b
        exit()
print 'NO'
