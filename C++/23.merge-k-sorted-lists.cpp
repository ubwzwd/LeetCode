/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (36.29%)
 * Likes:    3132
 * Dislikes: 207
 * Total Accepted:    478.3K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 * 
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        // merge here
        ListNode* head = MergeKListsRec(lists);
        return head;
    }

    ListNode* MergeKListsRec(vector<ListNode*> lists){
        if(lists.empty()) return nullptr;
        int len = lists.size();
        if(len == 1) return lists[0];
        if(len == 2) return MergeKListsHelper(lists[0], lists[1]);
        int mid = len/2;
        vector<ListNode*> sub_lists1(mid+1);
        vector<ListNode*> sub_lists2(len-mid-1);
        for(int i = 0; i <= mid; i++){
            sub_lists1[i] = lists[i];
        }
        for(int i = mid+1; i < len; i++){
            sub_lists2[i-mid-1] = lists[i];
        }
        ListNode* head1 = MergeKListsRec(sub_lists1);
        ListNode* head2 = MergeKListsRec(sub_lists2);
        return MergeKListsHelper(head1, head2);
    }

    ListNode* MergeKListsHelper(ListNode* l1, ListNode* l2){
        ListNode head(0);
        if(!l1 && !l2) return nullptr;
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* cur = &head;
        while(l1 || l2){
            if((l1 && l2 && l1->val < l2->val) || !l2){
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        return head.next;
    }
};
// @lc code=end

