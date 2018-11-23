/* 
Intersection of Two Linked Lists

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3

begin to intersect at node c1.


Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Use some mathematical way to find
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        if (lenA > lenB)
        {
            headA = forward_long_list(headA, lenA - lenB);
        }
        else if (lenB > lenA)
        {
            headB = forward_long_list(headB, lenB - lenA);
        }
        while (headA && headB)
        {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }

    int getLength(ListNode* head)
    {
        int len = 0;
        while(head)
        {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode* forward_long_list(ListNode* head, int difference_len)
    {
        while (head && difference_len)
        {
            head = head->next;
            difference_len--;
        }
        return head;
    }
};