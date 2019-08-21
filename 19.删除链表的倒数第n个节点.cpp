/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
      ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode *listPtr = head;
         if (head->next == NULL)
         {
             return NULL;
         }
        //  else
        //  {
        //     listPtr = head->next;
        //  }
         int count = 0;
         while (listPtr->next !=NULL && count < n)
         {
             listPtr = listPtr->next;
             count++;
         }
         ListNode * movePtr = head;
         while (listPtr->next!=NULL)
         {
             listPtr = listPtr->next;
             movePtr = movePtr->next;
         }
          if (movePtr == head && n!=count)
         {
            return head->next;
         }
         
         listPtr = movePtr->next;
         movePtr->next = movePtr->next->next;
         delete listPtr;
         return head;
        
        
    }
};

