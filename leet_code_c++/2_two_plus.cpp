#include<iostream>
#include<vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    /* data */
};

class  Solution
{
private:
    /* data */
public:
     Solution(/* args */);
    ~ Solution();
    // 操作链表的节点一定需要指针,操作一个链表至少需要两个指针(包括原来的指针)
    // 一个用来记录链表的头结点地址,另一个用来移动链表 
    // 添加链表不一样长时候的case
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
    // 翻转链表 将链表的第二个节点的指针指向第一个节点,
    // 第三个节点的指针指向第二个节点,以此类推,
    // 最后一个节点就成了头结点
    ListNode* reverse(ListNode* head){
        ListNode* p = head ;
        ListNode* q = p->next;
        ListNode* r;
        p->next = NULL;
        while (q != NULL)
        {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
            /* code */
        }
        return p;
        

    }

};

 Solution:: Solution(/* args */)
{

}

 Solution::~ Solution()
{
}
// 链表原序打印
void ListNodePrint(ListNode* head){
    while (head)
    {
        cout<<head->val<<"\t";
        head = head->next;
        /* code */
    }
    cout<<endl;
    
}
int main(int argc,char** argv){

    cout<<"two_listnode_num_sum"<<endl;
    ListNode* ptest1 = new ListNode(1);
    ListNode* ptest2 = new ListNode(0);
    // 诡异尝试链表构造
     ptest1->next = new ListNode(8);
     ptest1->next->next = new ListNode(3);
     ptest2->next = new ListNode(6);
   
    cout<<"listnode 1 :"<<endl;
    ListNodePrint(ptest1);
    cout<<"listnode 2 :"<<endl;
    ListNodePrint(ptest2);
    Solution two_sum;
    cout<<"two list_node add result :"<<endl;
    ListNode* reuult = two_sum.addTwoNumbers(ptest1,ptest2);
    //ListNode* reuult = two_sum.reverse(ptest2);
    ListNodePrint(reuult) ;
    cout<<endl;

    return 0;
}
