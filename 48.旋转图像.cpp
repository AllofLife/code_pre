/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */
class Solution {
public:
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

