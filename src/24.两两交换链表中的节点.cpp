/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
          if(head == NULL || head ->next== NULL)
        {
            return head;
        }
        ListNode* p = head;
        ListNode* q = p->next;
        ListNode* pro = p;

        while (p != NULL && p->next != NULL)
        {
            q = p->next;
            
           p->next = q->next;
           
           if(pro == head){
                q->next = pro;
                head = q;
           }else
           {
               pro->next = q;
               q->next = p;
           }
           pro = p;
           
           p = p->next; 
           
         
        }
    
    return head;
        
    }
};
// @lc code=end

