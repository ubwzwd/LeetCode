/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (35.85%)
 * Likes:    1435
 * Dislikes: 100
 * Total Accepted:    213K
 * Total Submissions: 592.5K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // if there's no or only 1 node
        if (!head || !head->next)
            return head;
        ListNode* pre_head = nullptr;
        ListNode* original_head = head;
        // pre_head is the (m-1)th node, and head is the m-th node
        for (int i = 1; i < m; i++) {
            pre_head = head;
            head = head->next;
        }
        // after_head is the node after the reversed part
        ListNode* after_head = head;
        // new_head is the head for the reversed part
        ListNode* new_head = nullptr;
        // next is the next node to be reversed
        ListNode* next = nullptr;
        // tail is the last node of the reversed part
        ListNode* tail = head;
        int change_length = n - m + 1;
        for (int i = 0; i < change_length; i++) {
            next = head->next;
            after_head = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
        }
        if (m == 1) {
            original_head = new_head;
        }
        else {
            pre_head->next = new_head;
        }
        tail->next = after_head;
        return original_head;
    }
};

