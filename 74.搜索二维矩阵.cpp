/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
     {
    //     // 二分查找 有几个注意点，第一个，左右指针，用大于小于等于
    //     // 用两次 二分查找 分别寻找行和列
    //     int m = matrix.size();
    //     if (m == 0)
    //     {
    //         return false;
    //     }
    //     int n = matrix[0].size();
    //     if (n == 0)
    //     {
    //         return false;
    //     }
    //     for (int i = 0; i < m; i++)
    //     {
    //         int hig = n - 1;
    //         int low = 0;
    //         int middle = (hig + low) / 2;
    //         if (matrix[i][hig] < target)
    //         {
    //             continue;
    //         }
    //         while(low <= hig){
    //              if (matrix[i][hig] < target)
    //             {
    //                 break;
    //             }
    //             if (matrix[i][middle] == target)
    //             {
                    
    //                 return true;
    //             }
    //             else if(matrix[i][middle] < target)
    //             {
    //                 low = middle + 1;
    //             }
    //             else if (matrix[i][middle] > target)
    //             {
    //                 hig = middle - 1;
    //             }
    //             middle = (hig + low) / 2;            
    //         } 
    //         if (matrix[i][middle] == target)
    //         {
    //            return true;
    //         }
             
           
            
    //     }     
    // return false;
    //  方法2 分治
         int m = matrix.size();
        if (m == 0)
        {
            return false;
        }
        int n = matrix[0].size();
        if (n == 0)
        {
            return false;
        }
        int i = m -1, j =0;
        while(i >= 0&& j < n){
            if (matrix[i][j] == target)
            {
                return true;
            }else if (matrix[i][j] > target)
            {
                i--;
            }
            else if (matrix[i][j] < target)
            {
                j++;
            }
          
            
            
        }
        return false;
    
    
    
    
    
    
     }
};
// @lc code=end

