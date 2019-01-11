// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

// Example:

// Input: head = 1->4->3->2->5->2, x = 3
// Output: 1->2->2->4->3->5

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

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // inisitalize lists
        ListNode temp1(0);
        ListNode temp2(0);
        ListNode * res1 = &temp1;
        ListNode * res2 = &temp2;
        while(head)
        {
            // put the values less than x in res1
            if (head->val < x)
            { 
                res1->next = head;
                res1 = res1->next;
                head = head->next;
            }
            else
            {
                res2->next = head;
                res2 = res2->next;
                head = head->next;
            }
        }
        res1->next = temp2.next;
        res2->next = NULL;
        return temp1.next;
    }
};

int main()
{
    /* code */

    return 0;
}
