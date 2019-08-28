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
   int searchInsert(vector<int>& nums, int target) {
       if (nums.size() == 0)
       {
           return 0;
       }
       
       int low,hight;
       low = 0;
       hight = nums.size() - 1;
       int middle = (low + hight) / 2;
       while (low <= hight)
       {
           if (nums[middle] < target)
           {
              low = middle + 1;
           }
           else if(nums[middle] > target)
           {
               hight = middle -1;
           }
           else
           {
               break;
           }
           
          middle = (low + hight) / 2;
           
       }

       return middle;
        
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
    
    cout<<"31 "<<endl;
    vector<int> nums;
    // nums.push_back(5);
    nums.push_back(5);
    nums.push_back(7);
    // nums.push_back(7);
    // nums.push_back(8);
    nums.push_back(8);
    nums.push_back(10);
    // nums.push_back(4);
    // nums.push_back(5);
    // nums.push_back(6);
    // nums.push_back(7);


    Solution s;
    int size =nums.size();   
    cout<<s.searchInsert(nums,7)<<endl;
    for_each(nums.begin(),nums.begin() + size,[](int ele){cout<<ele<<" ";});
    cout<<endl;
    
    
    
   
    return 0;
}
