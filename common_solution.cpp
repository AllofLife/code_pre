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
      void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size() - 1;
        // if(size % 2 == 0){
        //     size = size;
        // }


        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = i; j < matrix.size(); j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
            
        }
         for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j <= size / 2; j++)
            {
                // if (size % 2 == 0 && size / 2 == j)
                // {
                //    break;
                // }
                
                int tmp = matrix[i][j];
                // matrix[j][i] = matrix[size - j][i];
                // matrix[size - j][i] = tmp;
                matrix[i][j] = matrix[i][size - j];
                matrix[i][size - j] = tmp;
            }
            
        }
        
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
    vector<vector<int>> nums;
    nums.resize(3);
    
    nums[0].push_back(1);
    nums[0].push_back(2);
    nums[0].push_back(3);
    nums[1].push_back(4);
    nums[1].push_back(5);
    nums[1].push_back(6);
    nums[2].push_back(7);
    nums[2].push_back(8);
    nums[2].push_back(9);
    
    // nums[0].push_back(1);
    // nums[0].push_back(2);
    // nums[0].push_back(3);
    // nums[0].push_back(4);
    // nums[1].push_back(5);
    // nums[1].push_back(6);
    // nums[1].push_back(7);
    // nums[1].push_back(8);
    // nums[2].push_back(9);
    // nums[2].push_back(10);
    // nums[2].push_back(11);
    // nums[2].push_back(12);
    // nums[3].push_back(13);
    // nums[3].push_back(14);
    // nums[3].push_back(15);
    // nums[3].push_back(16);



    Solution s;
    // int size =nums.size();
    for_each(nums.begin(),nums.end(),printVV);
    // for_each(nums.begin(),nums.begin() + size,[](int ele){cout<<ele<<" ";});
    cout<<endl;
    s.rotate(nums);    
    for_each(nums.begin(),nums.end(),printVV);
   
    return 0;
}
