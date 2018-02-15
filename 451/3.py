import sys

from collections import defaultdict
from itertools import chain

def find_node(childs, ch):
    for n in childs:
        if n._ch == ch:
            return n
    return None


class BorNode(object):
    def __init__(self, ch):
        self._ch = ch
        self.childs = []

    def find_last_matching(self, s):
        if not s:
            return self, s
        n = find_node(self.childs, s[0])
        if not n:
            return self, s
        return n.find_last_matching(s[1:])

    def add_string(self, s):
        n, s = self.find_last_matching(s)
        if not s:
            return
        nn = BorNode(s[0])
        nn.add_string(s[1:])
        n.childs.append(nn)

    def __str__(self):
        return "ch: {}, rest: {}".format(self._ch, map(str, self.childs))

class Bor(BorNode):
    def __init__(self):
        super(Bor, self).__init__(None)

    def all_phones(self, n=None):
        n = n or self
        pref = n._ch or ''
        if not n.childs:
            return pref
        return [
            pref + suff
            for c in n.childs
            for suff in self.all_phones(c)
        ]

def read_record(line):
    fields = line.rstrip().split()
    return fields[0], fields[2:]

N = sys.stdin.readline()

d = defaultdict(Bor)
for line in sys.stdin:
    name, nums = read_record(line)
    bor = d[name]
    for n in nums:
        bor.add_string(n[::-1])

friends = d.items()
print len(friends)
for name, bor in friends:
    phones = bor.all_phones()
    plen = len(phones)
    phones = ' '.join(p[::-1] for p in phones)
    print '{} {} {}'.format(name, plen, phones)
