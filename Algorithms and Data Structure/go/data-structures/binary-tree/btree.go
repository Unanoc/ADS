package btree

import "fmt"

// Node ...
type Node struct {
	Value  int
	Parent *Node
	Right  *Node
	Left   *Node
}

// NewNode ...
func NewNode(value int) *Node {
	return &Node{Value: value}
}

// BinaryTree ...
type BinaryTree struct {
	Root *Node
	Size int
}

// NewTree ..
func NewTree(root *Node) *BinaryTree {
	if root == nil {
		return &BinaryTree{}
	}
	return &BinaryTree{Root: root, Size: 1}
}

// Add ...
func (b *BinaryTree) Add(value int) {
	node := NewNode(value)

	if b.Root == nil {
		b.Root = node
		b.Size++
		return
	}

	head := b.Root

	for {
		if node.Value > head.Value {
			if head.Right == nil {
				node.Parent = head
				head.Right = node
				b.Size++
				return
			}
			head = head.Right
		} else {
			if head.Left == nil {
				node.Parent = head
				head.Left = node
				b.Size++
				return
			}
			head = head.Left
		}
	}
}

// Delete ...
func (b *BinaryTree) Delete(value int) bool {
	head := b.Root

	nodeForDel, err := b.Search(value)
	if err != nil {
		return false
	}

	// node = root
	if nodeForDel.Parent == nil {
		b.Root = nil
		b.Size--
		return true
	}

	// node = leaf
	if nodeForDel.Left == nil && nodeForDel.Right == nil {
		head = nodeForDel.Parent
		nodeForDel.Parent = nil
		if head.Left.Value == value {
			head.Left = nil
		} else {
			head.Right = nil
		}
		b.Size--
		return true
	}

	if nodeForDel.Left == nil && nodeForDel.Right != nil {
		head = nodeForDel.Parent
		nodeForDel.Parent = nil
		if head.Left.Value == value {
			head.Left = nodeForDel.Right
		} else {
			head.Right = nodeForDel.Right
		}
		b.Size--
		return true
	}

	if nodeForDel.Left != nil && nodeForDel.Right == nil {
		head = nodeForDel.Parent
		nodeForDel.Parent = nil
		if head.Left.Value == value {
			head.Left = nodeForDel.Left
		} else {
			head.Right = nodeForDel.Left
		}
		b.Size--
		return true
	}
	// missed case when node has 2 children ... this method should be rewritten...
	return false
}

// Search ...
func (b *BinaryTree) Search(value int) (*Node, error) {
	head := b.Root

	for head != nil {
		if head.Value == value {
			return head, nil
		}
		if head.Value > value {
			head = head.Left
		} else {
			head = head.Right
		}
	}
	return nil, fmt.Errorf("value not found")
}

// PassingInOreder ...
func PassingInOreder(head *Node) {
	if head == nil {
		return
	}

	PassingInOreder(head.Left)
	fmt.Println(head.Value)
	PassingInOreder(head.Right)
}

// PassingPreOreder ...
func PassingPreOreder(head *Node) {
	if head == nil {
		return
	}

	fmt.Println(head.Value)
	PassingPreOreder(head.Left)
	PassingPreOreder(head.Right)
}

// PassingPostOreder ...
func PassingPostOreder(head *Node) {
	if head == nil {
		return
	}

	PassingPostOreder(head.Left)
	PassingPostOreder(head.Right)
	fmt.Println(head.Value)
}
