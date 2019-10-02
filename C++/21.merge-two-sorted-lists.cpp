/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (48.79%)
 * Likes:    2618
 * Dislikes: 380
 * Total Accepted:    676K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* new_head = nullptr;
        ListNode *tail = nullptr;
        while(l1 || l2){
            if((!l2)||(l1 && l1->val <= l2->val)){
                if(!new_head){
                    new_head = l1;
                    tail = l1;
                    l1 = l1->next;
                }
                else{
                    tail->next = l1;
                    l1 = l1->next;
                    tail = tail->next;
                }
            }
            else{
                if(!new_head){
                    new_head = l2;
                    tail = l2;
                    l2 = l2->next;
                }
                else{
                    tail->next = l2;
                    l2 = l2->next;
                    tail = tail->next;
                }
            }
        }
        return new_head;
    }
};

