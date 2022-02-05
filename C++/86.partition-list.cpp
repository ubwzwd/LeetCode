/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
//     ListNode(int x) : val(x), next(NULL) {}
// };
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode smaller_head(0);
        ListNode bigger_head(0);
        ListNode* smaller = &smaller_head;
        ListNode* bigger = &bigger_head;
        while(head){
            if(head->val < x){
                smaller->next = head;
                smaller = smaller->next;
                head = head->next;
            }
            else{
                bigger->next = head;
                bigger = bigger->next;
                head = head->next;
            }
        }
        smaller->next = bigger_head.next;
        bigger->next = nullptr;
        return smaller_head.next;
    }
};

