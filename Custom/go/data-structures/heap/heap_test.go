package heap

import (
	"fmt"
	"testing"
)

type Int int

func (x Int) Less(than Item) bool {
	return x < than.(Int)
}

func TestMinHeap(t *testing.T) {
	h := NewMin()

	h.Push(Int(8))
	h.Push(Int(7))
	h.Push(Int(6))
	h.Push(Int(3))
	h.Push(Int(1))
	h.Push(Int(0))
	h.Push(Int(2))
	h.Push(Int(4))
	h.Push(Int(9))
	h.Push(Int(5))

	sorted := make([]Int, 0)
	for h.Len() > 0 {
		head, err := h.Pop()
		if err != nil {
			t.Error()
		}
		sorted = append(sorted, head.(Int))
	}
	fmt.Println(sorted)
	for i := 0; i < len(sorted)-2; i++ {
		if sorted[i] > sorted[i+1] {
			fmt.Println(sorted)
			t.Error()
		}
	}
}

func TestMaxHeap(t *testing.T) {
	h := NewMax()

	h.Push(Int(8))
	h.Push(Int(7))
	h.Push(Int(6))
	h.Push(Int(3))
	h.Push(Int(1))
	h.Push(Int(0))
	h.Push(Int(2))
	h.Push(Int(4))
	h.Push(Int(9))
	h.Push(Int(5))

	sorted := make([]Int, 0)
	for h.Len() > 0 {
		head, err := h.Pop()
		if err != nil {
			t.Error()
		}
		sorted = append(sorted, head.(Int))
	}

	for i := 0; i < len(sorted)-2; i++ {
		if sorted[i] < sorted[i+1] {
			fmt.Println(sorted)
			t.Error()
		}
	}
}
