/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
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
};

