class TrieNode:
    def __init__(self, char: str):
        self.char = char
        self.children = []
        # Is it the last character of the word.`
        self.word_finished = False
        # How many times this character appeared in the addition process
        self.counter = 1


def add(root: TrieNode, word: str):
    node = root
    
    for char in word:
        found_in_child = False

        for child in node.children:
            if char == child.char:

                child.counter += 1
                node = child
                found_in_child = True
                break
        
        if not found_in_child:
            new_node = TrieNode(char)
            node.children.append(new_node)
            
            node = new_node

    node.word_finished = True


def find_prefix(root: TrieNode, prefix: str):
    node = root

    if not node:
        return False, 0
    
    for char in prefix:
        found_in_child = False

        for child in node.children:
            if char == child.char:
                found_in_child = True

                node = child

        if not found_in_child:
            return False, 0
    
    return True, node.counter

root = TrieNode('*')
add(root, "hackathon")
add(root, 'hack')

print(find_prefix(root, 'hac'))
print(find_prefix(root, 'hack'))
print(find_prefix(root, 'hackathon'))
print(find_prefix(root, 'ha'))
print(find_prefix(root, 'hammer'))