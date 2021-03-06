/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
class Solution {
public:
      int uniquePaths(int m, int n) {
        // 试试排列组合 在c++里头怎么使用的
        //   int ans = boost::math::factorial(flaot(m + n - 2)) / boost::math::factorial(float(m - 1)) / boost::math::factorial(float(n - 1 ));
        // return ans;
        // 也许是背包问题
        // vector<vector<int>> dp;
        //  先计算从(0,0)出发 到达 (i,j)的最小路径
        // 记录在数组里 遍历一遍就能把任意一个位置的路径找出来了.
        // 到达第一横排(0,i)坐标的路径就只有一条,同理的还有第一竖排坐标(i,0).
        int dp[m][n]={0};
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = 1;
        }
        // 到达任意一个坐标(i,j)的路径 计算方法为 
        // 到达 (i- 1)(j)的路径数加上(i)(j-1)的路径路 
        // 因为这两个点到目标位置的路径只有一条了
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
            
        }
        
        return dp[m - 1][n - 1];

    }
};

