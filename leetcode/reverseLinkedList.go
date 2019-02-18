package leetcode

// Развернуть односвязный список

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseBetween(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	left, right := head, head.Next.Next
	head = head.Next
	left.Next = nil

	for {
		head.Next = left

		if right == nil {
			break
		}

		left, head, right = head, right, right.Next
	}
	return head
}
