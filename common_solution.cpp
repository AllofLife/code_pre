#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<stack>
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
    void backtack(vector<string> &vresult,string scurrent, int open,int close,int max){
        if (open > max || close > max || close > open){
            return ;
        }
        if (open == max && close == max)
        {
            vresult.push_back(scurrent);
            return;
        }
        
       
        backtack(vresult,scurrent+"(",open+1,close,max);
        backtack(vresult,scurrent+")",open,close+1,max);
        return ;

            
            
            
     
        
    }
     vector<string> generateParenthesis(int n) {
     vector<string> result;
     backtack(result,"",0,0,n);
      return result;


    }
};
 Solution:: Solution(/* args */)
{

}

 Solution::~ Solution()
{

}
void printList(ListNode* head){
    ListNode* pList = head;
    while (pList->next!=NULL)
    {
        cout<<pList->val<<" ";
       pList = pList->next;
    }
     cout<<pList->val;
     cout<<endl;
    
}
void printString(string out){
    cout<<out<<endl;

}
int main(int argc,char** argv){
    
    cout<<"22 括号生成"<<endl;
    
    Solution s;
    vector<string> vs = s.generateParenthesis(3);
    for_each(vs.begin(),vs.end(),printString);
    
    
   
    return 0;
}
