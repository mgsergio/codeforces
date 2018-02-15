import sys
n = int(sys.stdin.readline())
r = n % 10
if r > 5:
    print n + 10 - r
else:
    print n - r
