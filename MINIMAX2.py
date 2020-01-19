import re


class Node:
    def __init__(self, index, an, bn):
        self.index = index
        self.an = an
        self.bn = bn
        self.parent = None


def subtree(node1, node2):
    if node2 is None:
        return False
    if node1.index == node2.index:
        return True
    return subtree(node1, node2.parent)


n = int(input())
node_list = []

a = input()
b = input()

a = re.split(' ', a)
b = re.split(' ', b)

for i in range(0, n):
    node_list.insert(i, Node(i+1, int(a[i]), int(b[i])))

for j in range(0, n - 1):
    edges = input()
    x, y = re.split(' ', edges)
    node_list[int(y)-1].parent = node_list[int(x)-1]

r = 0
for p in range(0, n):
    for q in range(0, n):
        if subtree(node_list[p], node_list[q]):
            r = r + min(max(int(a[p]), int(a[q])), max(int(b[p]), int(b[q])))

print(r)
