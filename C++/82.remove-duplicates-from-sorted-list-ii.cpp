/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (34.04%)
 * Likes:    1005
 * Dislikes: 85
 * Total Accepted:    199.1K
 * Total Submissions: 585.1K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->1->2->3
 * Output: 2->3
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return nullptr;
        else if (head->next)
        {
            if (!(head->next->next) &&head->val = head->next->val)
                return nullptr;
            ListNode *original_head = head;
            ListNode *prev = head;
            ListNode *before_dup = head;
            ListNode *dup = nullptr;
            head = head->next->next;
            prev = prev->next;
            while (head)
            {
                if (head->val == prev->val)
                {
                    dup = prev;
                    prev->next = head->next;
                    delete head;
                    head = prev->next;
                }
                else{
                    if(dup){
                        before_dup->next = head;
                        delete dup;
                        dup = nullptr;
                        prev = head;
                        head = head->next;
                    }
                    else{
                        
                    }        
                }
            }
        }
        else
            return head;
    }
};
