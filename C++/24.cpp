// 24. Swap Nodes in Pairs
// Given a linked list, swap every two adjacent nodes and return its head.

// Example:

// Given 1->2->3->4, you should return the list as 2->1->4->3.
// Note:

// Your algorithm should use only constant extra space.
// You may not modify the values in the list's nodes, only nodes itself may be changed.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
  private:
    ListNode *swapTwoNodes(ListNode *p)
    {
        if (!p || !p->next)
            return p;
        ListNode *current = p->next;
        ListNode *prev = p;
        prev->next = current->next;
        current->next = prev;
        return current;
    }

  public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head)
            return NULL;
        ListNode res{0};
        res.next = head;
        ListNode *temp = &res;
        while (temp && temp->next)
        {
            temp->next = swapTwoNodes(temp->next);
            temp = temp->next->next;
        }
        return res.next;
    }
};

int main()
{
    ListNode a{1};
    Solution s;
    ListNode *res = s.swapPairs(&a);
    return 0;
}