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
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = 0;
        int vsize = nums.size();
        while (j < vsize)
        {
            // cout<<nums[j]<<endl;
            if (nums[j]!=val)
            {
              nums[i] = nums[j];
               i++;
              
            }
            j++;
            
            
        }
        
        
       
        
        return i  ;
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
    
    cout<<"26 "<<endl;
    vector<int> nums;
    // nums.push_back(1);
    // nums.push_back(1);
    // nums.push_back(1);
    // nums.push_back(1);
    // nums.push_back(2);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(3);
    // nums.push_back(3);
    // nums.push_back(3);

    // nums.push_back(3);

    // nums.push_back(3);

    Solution s;
    int size = s.removeElement(nums,3);
    for_each(nums.begin(),nums.begin() + size,[](int ele){cout<<ele<<" ";});
    cout<<endl;
    
    
   
    return 0;
}
