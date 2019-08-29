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
   vector<int> candidates;
   vector<vector<int>> res;
   vector<int> path;
public:
     Solution(/* args */ );
    ~ Solution();
    void DFS(int start,int target){
        if (target == 0)
        {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size() && target - candidates[i] >=0; i++)
        {
            path.push_back(candidates[i]);
            DFS(i,target - candidates[i]);
            path.pop_back();
        }
        
    }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      sort(candidates.begin(),candidates.end());
      this->candidates = candidates;
      DFS(0,target);

        return res;
    }
};
 Solution:: Solution(/* args */)
{

}

 Solution::~ Solution()
{

}
void printVV(vector<int> vint ){
    for (vector<int>::iterator it = vint.begin(); it < vint.end(); it++){
        cout<<*it<<" ";
  
    }
    cout<<endl;
  
    
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
    
    cout<<"31 "<<endl;
    vector<int> nums;
    // nums.push_back(5);
    nums.push_back(2);
    nums.push_back(3);
    // nums.push_back(7);
    // nums.push_back(8);
    nums.push_back(6);
    nums.push_back(7);
    // nums.push_back(4);
    // nums.push_back(5);
    // nums.push_back(6);
    // nums.push_back(7);


    Solution s;
    int size =nums.size();
    vector<vector<int>>   vvresult;
    vvresult = s.combinationSum(nums,7);

    // cout<<s.combinationSum(nums,7)<<endl;
    for_each(nums.begin(),nums.begin() + size,[](int ele){cout<<ele<<" ";});
    cout<<endl;
    for_each(vvresult.begin(),vvresult.end(),printVV);
    
    
    
   
    return 0;
}
