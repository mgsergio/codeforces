#/usr/bin/python2.7

import sys
from itertools import imap, islice

def read_servers(s):
    return {
        ip: name
        for (name, ip) in imap(lambda x: x.split(), s)
    }

if __name__ == '__main__':
    n, m = map(int, sys.stdin.readline().split())

    s = read_servers(islice(sys.stdin, n))
    for line in sys.stdin:
        cmd, ip = line.rstrip('\n\r;').split()
        print '{} {}; #{}'.format(cmd, ip, s[ip])
