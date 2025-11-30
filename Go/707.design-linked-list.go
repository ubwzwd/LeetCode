/*
* @lc app=leetcode id=707 lang=golang
*
* [707] Design Linked List
*
* https://leetcode.com/problems/design-linked-list/description/
*
  - algorithms
  - Medium (29.29%)
  - Likes:    2945
  - Dislikes: 1668
  - Total Accepted:    442.6K
  - Total Submissions: 1.5M
  - Testcase Example:  '["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]\n' +
    '[[],[1],[3],[1,2],[1],[1],[1]]'

*
* Design your implementation of the linked list. You can choose to use a
* singly or doubly linked list.
* A node in a singly linked list should have two attributes: val and next. val
* is the value of the current node, and next is a pointer/reference to the
* next node.
* If you want to use the doubly linked list, you will need one more attribute
* prev to indicate the previous node in the linked list. Assume all nodes in
* the linked list are 0-indexed.
*
* Implement the MyLinkedList class:
*
*
* MyLinkedList() Initializes the MyLinkedList object.
* int get(int index) Get the value of the index^th node in the linked list. If
* the index is invalid, return -1.
* void addAtHead(int val) Add a node of value val before the first element of
* the linked list. After the insertion, the new node will be the first node of
* the linked list.
* void addAtTail(int val) Append a node of value val as the last element of
* the linked list.
* void addAtIndex(int index, int val) Add a node of value val before the
* index^th node in the linked list. If index equals the length of the linked
* list, the node will be appended to the end of the linked list. If index is
* greater than the length, the node will not be inserted.
* void deleteAtIndex(int index) Delete the index^th node in the linked list,
* if the index is valid.
*
*
*
* Example 1:
*
*
* Input
* ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get",
* "deleteAtIndex", "get"]
* [[], [1], [3], [1, 2], [1], [1], [1]]
* Output
* [null, null, null, null, 2, null, 3]
*
* Explanation
* MyLinkedList myLinkedList = new MyLinkedList();
* myLinkedList.addAtHead(1);
* myLinkedList.addAtTail(3);
* myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
* myLinkedList.get(1);              // return 2
* myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
* myLinkedList.get(1);              // return 3
*
*
*
* Constraints:
*
*
* 0 <= index, val <= 1000
* Please do not use the built-in LinkedList library.
* At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and
* deleteAtIndex.
*
*
*/
package main

// @lc code=start
type MyLinkedList struct {
	head   *myDoubleLinkedListNode
	tail   *myDoubleLinkedListNode
	length int
}

type myDoubleLinkedListNode struct {
	val  int
	next *myDoubleLinkedListNode
	prev *myDoubleLinkedListNode
}

func Constructor() MyLinkedList {
	return MyLinkedList{nil, nil, 0}
}

func (this *MyLinkedList) Get(index int) int {
	if index >= this.length {
		return -1
	}
	cur := this.head
	for i := 0; i < index; i++ {
		cur = cur.next
	}
	return cur.val
}

func (this *MyLinkedList) AddAtHead(val int) {
	newHead := &myDoubleLinkedListNode{val, nil, nil}
	this.length++
	if this.head == nil {
		this.head = newHead
		this.tail = this.head
		return
	}
	newHead.next = this.head
	this.head.prev = newHead
	this.head = newHead
}

func (this *MyLinkedList) AddAtTail(val int) {
	newTail := &myDoubleLinkedListNode{val, nil, nil}
	this.length++
	if this.tail == nil {
		this.tail = newTail
		this.head = this.tail
		return
	}
	newTail.prev = this.tail
	this.tail.next = newTail
	this.tail = newTail
}

func (this *MyLinkedList) AddAtIndex(index int, val int) {
	if index > this.length {
		return
	}
	if index == this.length {
		this.AddAtTail(val)
		return
	}
	if index == 0 {
		this.AddAtHead(val)
		return
	}
	// find the prev and next node
	newNode := &myDoubleLinkedListNode{val, nil, nil}
	prevNode := this.head
	for i := 0; i < index-1; i++ {
		prevNode = prevNode.next
	}
	nextNode := prevNode.next
	prevNode.next = newNode
	newNode.prev = prevNode
	nextNode.prev = newNode
	newNode.next = nextNode
	this.length++
}

func (this *MyLinkedList) DeleteAtIndex(index int) {
	if index < 0 || index >= this.length {
		return
	}
	// if delete at head
	if index == 0 && this.length > 1 {
		newHead := this.head.next
		newHead.prev = nil
		this.head.next = nil
		this.head = newHead
		this.length--
		return
	}
	if index == 0 && this.length == 1 {
		this.length--
		this.head = nil
		this.tail = nil
		return
	}
	// if delete at tail
	if index == this.length-1 {
		newTail := this.tail.prev
		newTail.next = nil
		this.tail.prev = nil
		this.tail = newTail
		this.length--
		return
	}
	// delete in the middle
	target := this.head
	for i := 0; i < index; i++ {
		target = target.next
	}
	prev := target.prev
	next := target.next
	target.prev = nil
	target.next = nil
	prev.next = next
	next.prev = prev
	this.length--
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Get(index);
 * obj.AddAtHead(val);
 * obj.AddAtTail(val);
 * obj.AddAtIndex(index,val);
 * obj.DeleteAtIndex(index);
 */
// @lc code=end
