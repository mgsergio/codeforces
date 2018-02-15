import sys

from collection import defaultdict


class Tree(object):
    def __init__(self, v, l, r):
        self.v = v
        self.l = l
        self.r = r

class TreeBuilder(object):
    def __init__(self):
        self.edges = defaultdict(list)

    def add(self, i, p):
        self.edges[i].append(p)
        self.edges[p].append(i)

    def build(self, root):
        q = [1]
        V = set()
        while q:
