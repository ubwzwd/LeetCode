// 2. Add Two Numbers

// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example:

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.

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
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1 && !l2)
            return NULL;
        ListNode head{0};
        ListNode *res = &head;
        int temp_sum;
        bool s = false;
        while (l1 || l2 || s==true)
        {
            if (s == false)
                temp_sum = 0;
            else
            {
                temp_sum = 1;
                s = false;
            }
            if (l1 && l2)
                temp_sum += l1->val + l2->val;
            else if (l1)
                temp_sum += l1->val;
            else if (l2)
                temp_sum += l2->val;
            if (temp_sum >= 10)
            {
                s = true;
                temp_sum -= 10;
            }
            ListNode *temp_node = new ListNode{temp_sum};
            res->next = temp_node;
            res = res->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        return head.next;
    }
};

int main()
{
    ListNode a1{2};
    ListNode a2{4};
    ListNode b1{5};
    ListNode b2{6};
    a1.next = &a2;
    b1.next = &b2;
    Solution s;
    ListNode* res = s.addTwoNumbers(&a1, &a2);
    return 0;
}