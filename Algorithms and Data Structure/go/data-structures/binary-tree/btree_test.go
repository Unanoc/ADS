package btree

import (
	"fmt"
	"testing"
)

func TestTree(t *testing.T) {
	// Test Add
	n := NewNode(1)
	tree := NewTree(n)

	tree.Add(4)
	tree.Add(2)
	tree.Add(5)
	tree.Add(3)
	tree.Add(6)

	if tree.Size != 6 {
		fmt.Println(tree.Size)
		t.Error()
	}

	// Test Search
	five, err := tree.Search(5)
	if err != nil {
		t.Error()
	}

	if five.Value != 5 ||
		five.Parent.Value != 4 ||
		five.Right.Value != 6 ||
		five.Left != nil {
		t.Error()
	}

	// Test Delete
	tree.Delete(5)

	if tree.Size != 5 {
		t.Error()
	}

	// Test Search after Delete
	four, err := tree.Search(4)
	if err != nil {
		t.Error()
	}

	if four.Right.Value != 6 ||
		four.Left.Value != 2 ||
		four.Parent.Value != 1 {
		t.Error()
	}
}
