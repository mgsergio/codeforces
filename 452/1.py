import sys

N = int(sys.stdin.readline())
gs = map(int, sys.stdin.readline().split())

ones, twos = 0, 0
for i in gs:
    if i == 1:
        ones += 1
    else:
        twos += 1

if twos >= ones:
    print ones
else:
    left = ones - twos
    print twos + left / 3
