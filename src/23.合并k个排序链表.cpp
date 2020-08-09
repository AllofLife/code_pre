/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 */

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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l1ptr = l1;
        ListNode* l2ptr = l2;
        ListNode * resultPtr = new ListNode(0);
        ListNode * r = resultPtr;
        while (l1ptr && l2ptr)
        {
            if (l1ptr->val > l2ptr->val )
            {
                r->next = l2ptr; 
                r = r->next;
                l2ptr = l2ptr->next;
            }
            else
            {
                
                r->next = l1ptr; 
                r = r->next;
                l1ptr = l1ptr->next;
                
            }
            
            
        }
        if (l1ptr)
            {
                r->next = l1ptr;
            }
            if (l2ptr)
            {
               r->next = l2ptr;
            }
        return resultPtr->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* return_ptr = nullptr;
        if (lists.size() == 0)
        {
            return return_ptr;
        }
        if(lists.size() == 1){
            return lists[0];
        }
        for (int i = 0; i < lists.size(); i++)
        {
           return_ptr =  mergeTwoLists(return_ptr,lists[i]);
        }
        return return_ptr;
        
        

        
    }
};
// @lc code=end

