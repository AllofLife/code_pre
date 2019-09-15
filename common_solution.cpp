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
      int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // 试试排列组合 在c++里头怎么使用的
        //   int ans = boost::math::factorial(flaot(m + n - 2)) / boost::math::factorial(float(m - 1)) / boost::math::factorial(float(n - 1 ));
        // return ans;
        // 也许是背包问题
        // vector<vector<int>> obstacleGrid;
        //  先计算从(0,0)出发 到达 (i,j)的最小路径
        // 记录在数组里 遍历一遍就能把任意一个位置的路径找出来了.
        // 到达第一横排(0,i)坐标的路径就只有一条,同理的还有第一竖排坐标(i,0).
        // int obstacleGrid[m][n]={0};
        if (obstacleGrid[0][0] == 1)
        {
            return 0;
        }
        obstacleGrid[0][0] = 1;
        
        for (int i = 1; i < m; i++)
        {
            obstacleGrid[i][0] = (obstacleGrid[i][0]==0 && obstacleGrid[i -1][0] == 1)? 1:0;
        }
        for (int i = 1; i < n; i++)
        {
            obstacleGrid[0][i] = (obstacleGrid[0][i]==0 && obstacleGrid[0][i - 1] == 1)? 1:0;
        }
        // 到达任意一个坐标(i,j)的路径 计算方法为 
        // 到达 (i- 1)(j)的路径数加上(i)(j-1)的路径路 
        // 因为这两个点到目标位置的路径只有一条了
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 0)
                {
                  obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                }
                else
                {
                    obstacleGrid[i][j] = 0;
                }
                
                
            }
            
        }
        
        return obstacleGrid[m - 1][n - 1];

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
    vector<vector<int>> nums;
    nums.resize(3);
    
    nums[0].push_back(0);
    nums[0].push_back(0);
    nums[0].push_back(0);
    nums[1].push_back(0);
    nums[1].push_back(1);
    nums[1].push_back(0);
    nums[2].push_back(0);
    nums[2].push_back(0);
    nums[2].push_back(0);
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
    // int size =nums.size();
    int result;
    result = s.uniquePathsWithObstacles(nums);
    cout<< result;
    

    // for_each(nums.begin(),nums.end(),printVV);
    // for_each(nums.begin(),nums.begin() + size,[](int ele){cout<<ele<<" ";});
    cout<<endl;
    // vector<vector<int>> vvResult ;
    // vector<int> vResult;
    // vResult =  s.spiralOrder(nums);
    // vvResult = s.generateMatrix(4);
    // for_each(vvResult.begin(),vvResult.end(),printVV);
    // for_each(vResult.begin(),vResult.end(),[](int ele){cout<<ele<<" ";});
  
    return 0;
}
