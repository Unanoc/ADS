class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


def display_list(root):
    tmp = root
    while tmp != None:
        print("[{}]->".format(tmp.value), end="")
        tmp = tmp.next
    print("NULL")


def add_last(root, value):
    tmp = root
    while tmp.next != None:
        tmp = tmp.next
    tmp.next = Node(value)

    return root


def add_first(root, value):
    node = Node(value)
    node.next = root

    return node


def remove_last(root):
    if root.next is None:
        return None

    tmp = root
    while tmp.next.next != None:
        tmp = tmp.next
    tmp.next = None

    return root

def remove_first(root):
    if root.next is None:
        return None

    tmp = root.next
    root.next = None

    return tmp
    



head = Node(0)
for i in range(1, 10):
    head = add_last(head, i)

display_list(head)

head = remove_first(head)
head = remove_last(head)

display_list(head)