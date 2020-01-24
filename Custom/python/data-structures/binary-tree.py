class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def add(root, value):
    if root:
        if root.value > value:
            if root.left is None:
                root.left = Node(value)
            else:
                add(root.left, value)
        else:
            if root.right is None:
                root.right = Node(value)
            else:
                add(root.right, value)
    else:
        root.value = value


def visit(root):
    if root:
        print(root.value)

def traverse_order(root, visit):
    if root:
        visit(root)
        traverse_order(root.left, visit)
        traverse_order(root.right, visit)

r = Node(5)
add(r, 1)
add(r, 2)
add(r, 3)
add(r, 4)
add(r, 6)
add(r, 7)
add(r, 8)

traverse_order(r, visit)