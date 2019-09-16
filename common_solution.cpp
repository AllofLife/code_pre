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

public:
     Solution(/* args */ );
    ~ Solution();
  vector<int> plusOne(vector<int>& digits) {
        bool plus = true;
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--)
        {
           if ((digits[i] + 1) / 10)
           {
               digits[i] = digits[i] + 1;
               cout<<digits[i]<<endl;
               if (digits[i] >= 10 )
               {
                  cout<<"sss"<<endl;
                   digits[i] = 0;
                   plus =true;
               }
               else
               {
                   return digits;
               }
               
               
           }
           else
           {
               if (plus)
               {
                     digits[i] = digits[i] + 1;
                     plus = false;
               }
               
            
           }
           
           
           
           
        }
        if (plus)
           {
            //    digits.insert(digits.begin(),1);
            digits[0] = 1;
            digits.push_back(0);
            cout<<"end"<<digits[0]<<endl;
           }
        return digits;
        

        
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
    
    cout<<"62 "<<endl;
    vector<int> nums;
    // nums.resize(3);
    
    // nums[0].push_back(1);
    // nums[0].push_back(3);
    // nums[0].push_back(1);
    // nums[1].push_back(1);
    // nums[1].push_back(5);
    // nums[1].push_back(1);
    // nums[2].push_back(4);
    // nums[2].push_back(2);
    // nums[2].push_back(1);
    // nums[3].push_back(15);
    // nums[3].push_back(18);
    
    // nums[0].push_back(1);
    // nums[0].push_back(2);
    // nums[0].push_back(3);
    // nums[0].push_back(4);
    // nums[0].push_back(5);
    // nums[0].push_back(6);
    // nums[0].push_back(7);
    // nums[0].push_back(8);
    // nums[0].push_back(9);
    // nums[0].push_back(10);
    // nums[2].push_back(11);
    // nums[2].push_back(12);
    // nums[3].push_back(13);
    // nums[3].push_back(14);
    // nums[3].push_back(15);
    // nums[3].push_back(16);


    // nums.push_back(2);
    // nums.push_back(3);
    // nums.push_back(1);
    // nums.push_back(1);
    // nums.push_back(4);

    //   nums.push_back(3);
    // nums.push_back(2);
    // nums.push_back(1);
    // nums.push_back(0);
    nums.push_back(9);
    nums.push_back(9);
    
    Solution s;
    // int size =nums.size();
    vector<int> result;
    result = s.plusOne(nums);
    cout<< result[0]<<endl;
    

    // for_each(nums.begin(),nums.end(),printVV);
    for_each(result.begin(),result.end() - 1,[](int ele){cout<<ele<<" ";});
    cout<<endl;
    // vector<vector<int>> vvResult ;
    // vector<int> vResult;
    // vResult =  s.spiralOrder(nums);
    // vvResult = s.generateMatrix(4);
    // for_each(vvResult.begin(),vvResult.end(),printVV);
    // for_each(vResult.begin(),vResult.end(),[](int ele){cout<<ele<<" ";});
  
    return 0;
}
