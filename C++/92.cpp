/* 
Reverse Linked List II

Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:
Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
 */

/* *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * }; */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        ListNode *original_head = head;
        ListNode *pre_head = NULL;
        for (int i = 1; i < m; i++)
        {
            pre_head = head;
            head = head->next;
        }
        ListNode *after_head = head;
        ListNode *new_head = NULL;
        ListNode *next = NULL;
        ListNode *tail = NULL;
        int change_length = n - m + 1;
        for (int i = 0; i < change_length; i++)
        {
            next = head->next;
            head->next = new_head;
            new_head = head;
            tail = head;
            head = next;
        }
        if (m == 1)
        {
            original_head = tail;
        }
        else
        {
            pre_head->next = tail;
        }
        after_head->next = head;
        return original_head;
    }
};