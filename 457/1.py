import sys

x = int(sys.stdin.readline())
hh, mm = map(int, sys.stdin.readline().split())

def happy(mm):
    hh, mm = tohourmin(mm)
    return ('7' in str(hh)) or ('7' in str(mm))

def tomin(hh, mm):
    return hh * 60 + mm

def tohourmin(mm):
    return mm / 60, mm % 60

k = 0
mm = tomin(hh, mm)
while not happy(mm):
    mm -= x
    k += 1

print(k)
