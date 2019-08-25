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
    int search(vector<int>& nums, int target) {
         if (nums.size() == 0)
        {
            return -1;
        }
        if (nums.size() == 1)
        {
            if (nums[0]==target)
            {
               return 0;
            }
            else
            {
                return -1;
            }
              
        }
        if (nums.size() == 2)
        {
            if (nums[0]==target)
            {
               return 0;
            }
            else if(nums[1]==target)
            {
                return 1;
            }
            
            else
            {
                return -1;
            }
        }
        
        int vsize = nums.size();
        int i = vsize - 1;
        while (i >= 0 && nums[i] > nums[i -1])
        {
            i--;
        }
        cout<<"i "<<i<<nums[i]<<endl;
        cout<<"size - 1 "<<nums[vsize -1]<<endl;
        
        if (nums[i] <= target && nums[vsize - 1] >= target )
        {
           return binary_search(nums.begin() + i,nums.end(),target) + 1;
        }
        else if (nums[0] <= target && nums[i - 1] >= target)
        {
            cout<<"i"<<i<<"target"<<target<<endl;
           return binary_search(nums.begin(),nums.begin()+ i -1,target) - 1;
        }
        return -1;
    
          
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
    nums.push_back(1);
    nums.push_back(3);
    // nums.push_back(4);
    // nums.push_back(5);
    // nums.push_back(6);
    // nums.push_back(7);
    // nums.push_back(0);
    // nums.push_back(1);
    // nums.push_back(2);

    Solution s;
    int size =nums.size();
    cout<<s.search(nums,0)<<endl;
    for_each(nums.begin(),nums.begin() + size,[](int ele){cout<<ele<<" ";});
    cout<<endl;
    
    
   
    return 0;
}
