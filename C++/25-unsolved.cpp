// 25. Reverse Nodes in k-Group

// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

// Example:

// Given this linked list: 1->2->3->4->5

// For k = 2, you should return: 2->1->4->3->5

// For k = 3, you should return: 3->2->1->4->5

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
  private:
    // swap p and p+1
    ListNode *swapOneGroup(ListNode *pre, ListNode *nex)
    {
        ListNode * last = pre->next;
        ListNode * cur = last->next;
        while(cur->next != nex)
        {
            last->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = last->next;
        }
        //return the last node, all nodes are coinnected already
        return last;
    }
  public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if(head == NULL || k == 1) return head;
        int len = 0;
        ListNode * res = new ListNode{0};
        res->next = head;
        // current: node 0, pre: before head, next: node 1
        ListNode * current = head, *pre = res, *nex = head->next;
        // get the length of the linked list
        while(current)
        {
            current = current->next;
            len+=1;
        }
        current = head;
        for(int i = 1; i<len;i++)
        {
            if(i%k==0)
            {
                nex = current->next;
                pre = swapOneGroup(current, nex);
                current = pre->next;
            }
            else
            {
                current = current->next;
            }
            
        }
        return res->next;
    }
};

int main()
{
    ListNode a{1};
    ListNode b{2};
    ListNode c{3};
    ListNode d{4};
    ListNode e{5};
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    Solution s;
    ListNode * res = s.reverseKGroup(&a,2);
}