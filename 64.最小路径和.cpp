/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
class Solution {
public:
   int minPathSum(vector<vector<int>>& grid) {
        //  二维的动态规划
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n] = {0};
        // 先处理醉特殊的一行一列

        dp[0][0] =grid[0][0];
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = grid[i][0] + dp[i - 1][0];

        }
         for (int i = 1; i < n; i++)
        {
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
               dp[i][j] = grid[i][j] + min(dp[i][j - 1],dp[i - 1][j]);
            }
            
        }
        
    return dp[m - 1][n -1 ];
    //  return dp[2][2];

    }
};

