// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

// To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// using two pointers, one faster and one slower. If the two pointers meet, there's a cycle.
class Solution
{
  public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *meet;
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
            if (!fast)
                return NULL;
            fast = fast->next;
            if (fast == slow)
            {
                meet = fast;
                break;
            }
        }
        if (meet == NULL)
            return NULL;
        while (head && meet)
        {
            if (head == meet)
                return head;
            head = head->next;
            meet = meet->next;
        }
        return NULL;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
