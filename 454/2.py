import sys

from itertools import islice

def read_field():
    return filter(lambda x: x, [
        list(line.rstrip().replace(' ', ''))
        for line in map(lambda _: sys.stdin.readline(), range(11))
    ])

class SmallFiled:
    def __init__(self, f, x, y):
        self.x = x
        self.y = y
        self.f = f

    def coord(self, x, y):
        return 3 * self.x + x, 3 * self.y + y

    def __call__(self, x, y):
        return self.get(x, y)

    def get(self, x, y):
        i, j = self.coord(x, y)
        return self.f[i][j]

    def set(self, x, y, v):
        i, j = self.coord(x, y)
        self.f[i][j] = v

def is_all_filled(sf):
    for i in range(3):
        for j in range(3):
            if sf(i, j) == '.':
                return False
    return True

def mark_all_empty(bf):
    for i in range(9):
        for j in range(9):
            if bf[i][j] == '.':
                bf[i][j] = '!'
    return bf

def find_move(fs, bf, x, y, xx, yy):
    sf = fs[x][y]
    x, y = sf.coord(0, 0)
    sf = fs[xx - x][yy - y]
    if is_all_filled(sf):
        return mark_all_empty(bf)
    for i in range(3):
        for j in range(3):
            if sf(i, j) == '.':
                sf.set(i, j, '!')
    return bf

def print_filed(bf):
    for i in range(9):
        for j in range(9):
            sys.stdout.write(bf[i][j])
            if j == 2 or j == 5:
                print ' ',
        print
        if i == 2 or i == 5:
            print


big_field = read_field()
fields = [
    [
        SmallFiled(big_field, i, j)
        for j in range(3)
    ]
    for i in range(3)
]

# from pprint import pprint
# pprint(big_field)
x, y = map(int, sys.stdin.readline().split())
x -= 1
y -= 1

#fields[2][1].set(0, 0, '?')

res = find_move(fields, big_field, x / 3, y / 3, x, y)
print_filed(res)
