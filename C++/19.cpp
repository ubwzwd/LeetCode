// 19. Remove Nth Node From End of List
// Given a linked list, remove the n-th node from the end of list and return its head.

// Example:

// Given linked list: 1->2->3->4->5, and n = 2.

// After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:

// Given n will always be valid.

/**
 * Definition for singly-linked list.
 
 */

#include <iostream>
#include <vector>

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
            return NULL;
        int len = 0;
        // if ((!head->next) && (n == 1))
        //     return NULL;
        // if ((!head->next) && (n != 1))
        //     return head;
        ListNode *temp = head;
        while (temp)
        {
            len++;
            temp = temp->next;
        }
        // we want to remove the (len-n)th node, start from 0
        n = len - n;
        // consider if we need to remove the head
        if (n == 0)
        {
            // remove head
            temp = head->next;
            delete head;
            return temp;
        }
        else
        {
            int i;
            temp = head;
            // go to the node before the one we want to remove
            for (i = 0; i < n - 1; i++)
            {
                temp = temp->next;
            }
            // now temp->next is what we want to remove
            ListNode *remove_node = temp->next;
            temp->next = remove_node->next;
            delete remove_node;
            return head;
        }
    }
};