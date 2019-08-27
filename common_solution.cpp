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
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0)
        {
            return vector<int> {-1,-1};
        }
        if (nums.size()==1)
        {
            if (nums[0]==target)
            {
              return vector<int> {0,0};
            }
            
            
            return vector<int> {-1,-1};
        }
        int first = 0;
        int last = nums.size();
        int mid = (first + last) / 2;
         int l = 0,r = 0;
         // 找左边界
         while (first < last)
         {
           if (nums[mid] == target)
           {
               last = mid;
           }
           else if (nums[mid] > target)
           {
               last = mid;
           }
           else if(nums[mid] < target)
           {
               first = mid + 1;
           }
           cout<<"mid "<<mid<<" first "<<first<<" last "<<last<<endl;
            mid = (first  + last ) / 2;
            
           
         }
        //  cout<<"mid "<<mid<<endl;
        //  cout<<"first "<<first<<endl;
         l = first;
         // 找右边界
         first = 0;
         last = nums.size();
         mid = (first + last) / 2;
         while (first < last)
         {
           if (nums[mid] == target)
           {
               first = mid + 1;
           }
           else if (nums[mid] > target)
           {
               last = mid;
           }
           else if(nums[mid] < target)
           {
               first = mid + 1;
           }
            mid = (first  + last ) / 2;
           
         }
         r = last -1;
        //  cout<<"first "<<l<<" last: "<<r<<endl;
        if (r < l)
        {
            return vector<int> {-1 ,-1};
        }
        
        return vector<int> {l ,r};
        
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
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(10);
    // nums.push_back(4);
    // nums.push_back(5);
    // nums.push_back(6);
    // nums.push_back(7);


    Solution s;
    int size =nums.size();
    vector<int> vre = s.searchRange(nums,6);
    // cout<<s.search(nums,0)<<endl;
    for_each(nums.begin(),nums.begin() + size,[](int ele){cout<<ele<<" ";});
    cout<<endl;
    for_each(vre.begin(),vre.begin() + 2,[](int ele){cout<<ele<<" ";});
    cout<<endl;
    
    
   
    return 0;
}
