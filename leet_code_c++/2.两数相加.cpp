/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
       ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
        // ListNode* rl1 = reverse(l1);
        // ListNode* rl2 = reverse(l2);
        ListNode* rl1 = l1;
        ListNode* rl2 = l2;
        int isum = 0;
        int iforward = 0;
        ListNode* pr_l1  = rl1;
        ListNode* pr_l2  = rl2;
        ListNode* pr = new ListNode(0);
        ListNode* pr_sum = pr;
        while (pr_l1&&pr_l2)
        {
            isum = pr_l2->val + pr_l1->val + iforward;
            iforward = isum / 10;
            ListNode* p_tem = new ListNode(0);
            p_tem->val = isum % 10;
            pr->next = p_tem;
            // 指针移动
            pr = pr->next;
            pr_l1 = pr_l1->next;
            pr_l2 = pr_l2->next;
            /* code */


        }
        int tmp = 0;
        while (pr_l1)
        {
            pr->next = pr_l1;
            pr = pr->next;
            pr_l1 = pr_l1->next;
            cout<<iforward<<endl;
            tmp = iforward;
            iforward = (pr->val + iforward)/10;
            pr->val = (pr->val + tmp)%10;
        }
        while (pr_l2)
        {
           pr->next = pr_l2;
           pr_l2 = pr_l2->next;
           pr = pr->next;
           tmp = iforward;
           iforward = (pr->val + iforward)/10;
           pr->val = (pr->val + tmp)%10;
        }
        if(iforward){
            pr->next = new ListNode(iforward);
            }        
        
     
        
        //return reverse(pr_sum->next);
        return pr_sum->next;
        

    }


};

