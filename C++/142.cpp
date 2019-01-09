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

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

// using set to find cycle
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> s;
        while (head!=NULL)
        {
            if (s.find(head)==s.end())
            {
                s.insert(head);
                head = head->next;
            }
            else{
                return head;
            }
        }
        return NULL;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
