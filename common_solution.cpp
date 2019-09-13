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
       vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int>  ans;
        if (matrix.empty())
        {
            return ans;
        }
         
        // vector<vector<int>> vv_bool;
        // 调试真的好难呀
        int R_size = matrix.size(), C_size = matrix[0].size();
        // cout<<R_size<<C_size<<endl;
        int vv_bool[R_size][C_size] = {0,0} ;
        for (int i = 0; i < R_size; i++)
        {
           for (int j = 0; j < C_size; j++)
           {
            //   cout<<vv_bool[i][j]<<" ";
            vv_bool[i][j] = 0;
           }

           
        }
       
        
        int r = 0,c = 0;
        int dic_r[4] = {0,1,0,-1};
        int dic_c[4] = {1,0,-1,0};
        int det = 0;
        // 前进的方向
        for (int i = 0; i < R_size * C_size; i++)
        {
            // cout<<matrix[r][c]<<" i "<<i<<endl;
            ans.push_back(matrix[r][c]);
            vv_bool[r][c] = i + 1;
            int cr = r + dic_r[det];
            int cc = c + dic_c[det];
            // cout<<"det "<<det<<" cr "<<cr<<" cc "<<cc<<endl;
            
            
            // 确保 matrix[r][c] 没有超出范围
            if (0 <= cc && cc < C_size && 0 <= cr && cr < R_size  && vv_bool[cr][cc] == 0)
            {
            
                // 还在范围内就继续直走
                r = cr;
                c = cc;
                // cout<<" r " <<r<<" c "<<c<<endl;

            }
            else
            {
                // cout<<"转弯"<<endl;
                // 不在范围内就转个弯
                det = (det + 1) % 4;
                // cout<<" else det "<<det<<endl;
                r = r + dic_r[det];
                c = c + dic_c[det];
                // cout<<" r " <<r<<" c "<<c<<endl;
                

            }
            
            
        }
         for (int i = 0; i < R_size; i++)
        {
           for (int j = 0; j < C_size; j++)
           {
              cout<<vv_bool[i][j]<<" ";
            // vv_bool[i][j] = 0;
           }

           cout<<endl;
        }
        
        return ans;
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vvtest;
        vvtest.resize(n);
        
        for (int i = 0; i < n; i++)
        {
           for (int j = 0; j < n; j++)
           {
               vvtest[i].push_back(0);
           }
           
        }

        int R_size = n, C_size = n;
        // cout<<R_size<<C_size<<endl;
        int vv_bool[R_size][C_size] = {0,0} ;
        for (int i = 0; i < R_size; i++)
        {
           for (int j = 0; j < C_size; j++)
           {
            //   cout<<vv_bool[i][j]<<" ";
            vv_bool[i][j] = 0;
           }

           
        }
       
        
        int r = 0,c = 0;
        int dic_r[4] = {0,1,0,-1};
        int dic_c[4] = {1,0,-1,0};
        int det = 0;
        // 前进的方向
        for (int i = 0; i < R_size * C_size; i++)
        {
            // cout<<matrix[r][c]<<" i "<<i<<endl;
            // ans.push_back(matrix[r][c]);
            vv_bool[r][c] = i + 1;
            vvtest[r][c] = i + 1;
            int cr = r + dic_r[det];
            int cc = c + dic_c[det];
            // cout<<"det "<<det<<" cr "<<cr<<" cc "<<cc<<endl;
            
            
            // 确保 matrix[r][c] 没有超出范围
            if (0 <= cc && cc < C_size && 0 <= cr && cr < R_size  && vv_bool[cr][cc] == 0)
            {
            
                // 还在范围内就继续直走
                r = cr;
                c = cc;
                // cout<<" r " <<r<<" c "<<c<<endl;

            }
            else
            {
                // cout<<"转弯"<<endl;
                // 不在范围内就转个弯
                det = (det + 1) % 4;
                // cout<<" else det "<<det<<endl;
                r = r + dic_r[det];
                c = c + dic_c[det];
                // cout<<" r " <<r<<" c "<<c<<endl;
                

            }
            
            
        }
        
        return vvtest;
        
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
    // nums.push_back(4);
    
    
    Solution s;
    int size =nums.size();
    // for_each(nums.begin(),nums.end(),printVV);
    // for_each(nums.begin(),nums.begin() + size,[](int ele){cout<<ele<<" ";});
    cout<<endl;
    vector<vector<int>> vvResult ;
    // vector<int> vResult;
    // vResult =  s.spiralOrder(nums);
    vvResult = s.generateMatrix(4);
    for_each(vvResult.begin(),vvResult.end(),printVV);
    // for_each(vResult.begin(),vResult.end(),[](int ele){cout<<ele<<" ";});
  
    return 0;
}
