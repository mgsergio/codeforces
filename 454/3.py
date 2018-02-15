import sys

s = set()
u = set()

N = int(sys.stdin.readline())
k = 0
lines = [line for line in sys.stdin]

for line in lines[:-1]:
    a, w = line.rstrip().split()
    if (len(u) == 1 or len(s) == 25) and a != '.':
        k += 1
        continue
    if a == '!':
        if u:
            s.update(u.symmetric_difference(w))
            u.intersection_update(w)
        else:
            u.update(i for i in w if i not in s)
    elif a == '?':
        s.add(w)
        u.discard(w)
    else:  # a == '.'
        s.update(w)
        u.difference_update(w)

print k
