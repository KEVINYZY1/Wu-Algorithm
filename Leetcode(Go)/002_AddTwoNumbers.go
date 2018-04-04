package Leetcode


type ListNode struct {
	Val int
    Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    dummy := &ListNode{ Val: 0 }//构造节点
    p := dummy
    carry := 0

    for l1 != nil || l2 != nil {//for可以当while用
        add := carry
        if l1 != nil {
            add += l1.Val
            l1 = l1.Next
        }
        if l2 != nil {
            add += l2.Val
            l2 = l2.Next
        }
        carry = add / 10
        add = add % 10
        p.Next = &ListNode{ Val: add }
        p = p.Next
    }

    if carry != 0 {
        p.Next = &ListNode{ Val: carry }
    }

    return dummy.Next
}