import sys

from itertools import cycle, izip, islice

ms = [
    31, # January
    28, # February
    31, # March
    30, # April
    31, # May,
    30, # June,
    31, # July,
    31, # August,
    30, # September,
    31, # October,
    30, # November,
    31, # December.
]

msl = [
    31, # January
    29, # February
    31, # March
    30, # April
    31, # May,
    30, # June,
    31, # July,
    31, # August,
    30, # September,
    31, # October,
    30, # November,
    31, # December.
]

N = int(sys.stdin.readline())
days = map(int, sys.stdin.readline().split())

def is_pref(a, b):
    return all(
        map(lambda x: x[0] == x[1], izip(a, b))
    )

def contains(a, b, len_a):
    for i in xrange(len_a):
        if is_pref(islice(cycle(a), i, i + len_a), b):
            return True
    return False

if N <= len(ms):
    y = (
        contains(ms, days, 24) or
        contains(ms + msl, days, 48)
    )
    if y:
        print 'YES'
    else:
        print 'NO'

else:
    y = (
        contains(ms, days, 48) or
        contains(ms + msl, days, 96)
    )
    if y:
        print 'YES'
    else:
        print 'NO'
