class Node(object):
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class Tree(object):
    def __init__(self):
        self.root = None

tree = Tree()

def insert(x):
    parent = None
    v = tree.root
    while v is not None:
        parent = v
        if x < v.key:
            v = v.left
        elif x > v.key:
            v = v.right
        else:  # x == v.key
            return
    w = Node(x)
 
    if parent is None:
        tree.root = w
    elif x < parent.key:
        parent.left = w
    elif x > parent.key:
        parent.right = w

fin = open("input.txt", "r")
fout = open("output.txt", "w")

for i in fin:
    tree.root = insert(int(i.strip()))

def leftorder_traverse(root, fout):
    if root is not None:
        fout.write(str(root.key) + "\n")
        leftorder_traverse(root.left, fout)
        leftorder_traverse(root.right, fout)

leftorder_traverse(tree.root, fout)

fin.close()
fout.close()
