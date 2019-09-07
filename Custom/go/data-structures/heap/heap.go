package heap

import (
	"fmt"
	"sync"
)

type Item interface {
	Less(than Item) bool
}

type Heap struct {
	sync.Mutex
	data []Item
	min  bool
}

func NewMin() *Heap {
	return &Heap{
		data: make([]Item, 0),
		min:  true,
	}
}

func NewMax() *Heap {
	return &Heap{
		data: make([]Item, 0),
	}
}

func (h *Heap) IsEmpty() bool {
	return len(h.data) == 0
}

func (h *Heap) Len() int {
	return len(h.data)
}

func (h *Heap) Get(n int) Item {
	return h.data[n]
}

func (h *Heap) Compare(a, b Item) bool {
	if h.min {
		return a.Less(b)
	} else {
		return b.Less(a)
	}
}

func (h *Heap) BuildHeap(sourceSlice []Item) {
	for i := len(sourceSlice) / 2; i >= 0; i-- {
		h.siftDown(i)
	}
}

func (h *Heap) siftUp(id int) {
	var parent int
	for id != 0 {
		parent = (id - 1) / 2
		if h.Compare(h.data[parent], h.data[id]) {
			return
		}
		h.data[parent], h.data[id] = h.data[id], h.data[parent]
		id = parent
	}
}

func (h *Heap) siftDown(id int) {
	leftChild := 2*id + 1
	rightChild := 2*id + 2

	current := id

	if leftChild < h.Len() && h.Compare(h.data[leftChild], h.data[current]) {
		current = leftChild
	}
	if rightChild < h.Len() && h.Compare(h.data[rightChild], h.data[current]) {
		current = rightChild
	}

	if current != id {
		h.data[current], h.data[id] = h.data[id], h.data[current]
		h.siftDown(current)
	}
}

func (h *Heap) Push(n Item) {
	h.Lock()
	defer h.Unlock()

	h.data = append(h.data, n)
	h.siftUp(h.Len() - 1)
}

func (h *Heap) Pop() (el Item, err error) {
	h.Lock()
	defer h.Unlock()

	if h.Len() == 0 {
		err = fmt.Errorf("heap is empty")
		return el, err
	}

	head := h.data[0]
	last := h.data[h.Len()-1]
	if h.Len() == 1 {
		h.data = nil
		return head, nil
	}

	h.data = append([]Item{last}, h.data[1:h.Len()-1]...)
	h.siftDown(0)

	return head, nil
}
