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
    void nextPermutation(vector<int>& nums) {
        if (nums.size()==0)
        {
           return ;
        }
        
        // int max_order = nums[0];
        int i  =nums.size() -2 ;

        for (; i >= 0; i--)
        {
            // 找到第一个下降的地方
            if (nums[i] < nums[i + 1])
            {
                // cout<<nums[i]<<nums[i+1]<<endl;
                break;
            }
            
        }
        if(i >= 0){
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i])
            {
               j--;
            }
            // cout<<nums[i]<<nums[j]<<endl;
            int tmp = nums[j];
            nums[j] = nums[i];
            nums[i] = tmp;
            // return;
        }
        // cout<<"i"<<i<<endl;
        // 把后面的数排序
        sort(nums.begin()+i+1,nums.end());
        
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
    // nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(3);
    // nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(3);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);


    Solution s;
    int size =nums.size();
    // int size = s.nextPermutation(nums);
    s.nextPermutation(nums);
    for_each(nums.begin(),nums.begin() + size,[](int ele){cout<<ele<<" ";});
    cout<<endl;
    
    
   
    return 0;
}
