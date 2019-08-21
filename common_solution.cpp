#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    };
class  Solution
{
private:
   
public:
     Solution(/* args */ );
    ~ Solution();
     ListNode* removeNthFromEnd(ListNode* head, int n) {
         ListNode *listPtr = head;
         if (head->next == NULL)
         {
             return NULL;
         }
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
         cout<<"count "<<count<<endl;
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
 Solution:: Solution(/* args */)
{

}

 Solution::~ Solution()
{

}
void printRes2(int val){
    cout<<val<<" ";
}
void printRes(vector<int> &s){
    for_each(s.begin(),s.end(),printRes2);
}
int main(int argc,char** argv){
    
    cout<<"19 删除链表倒数第n个节点"<<endl;
    
    ListNode test_head(1);
    ListNode* listptr = &test_head;
    test_head.next = new ListNode(2);
    // test_head.next->next = new ListNode(3);
    // test_head.next->next->next = new ListNode(4);
    // test_head.next->next->next->next = new ListNode(5);
    Solution s;
    

    listptr = s.removeNthFromEnd(&test_head,2);
    // listptr = &test_head;
    while (listptr->next!=NULL)
    {
       cout<<listptr->val<<" ";
       listptr = listptr->next;
    }
    cout<<listptr->val<<" ";
    cout<<endl;

    
    // for_each(result.begin(),result.end(),printRes);
   
    return 0;
}
