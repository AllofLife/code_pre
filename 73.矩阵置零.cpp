/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 既然矩阵里面有零的话就要把这一行和这一列都去掉，
        // 那么可以把这一行和这一列用来记录哪些行和列需要清零
        int row = -1,cel = -1;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j]==0)
                {
                    row = i;
                    cel =j;
                    break;
                }
                
            }
               if (row != -1){
                   break;
               }
            
        }
        if (row == -1)
        {
            return;
        }
        // find the zero

        for (int i = 0; i < matrix.size(); i++)
        {
            if (i == row)
            {
                continue;
            }
            
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (j == cel)
                {
                    continue;
                }
                
                if (matrix[i][j]==0)
                {
                    matrix[i][cel] = 0;
                    matrix[row][j] = 0;
                  
                }
                
            }
               
            
        }
    // set the cel to Zeroes
    for (int i = 0; i <matrix[0].size() ; i++)
    {
        if (matrix[row][i] == 0 && i!=cel){
           for (int j = 0; j < matrix.size(); j++){
            matrix[j][i] = 0;
            }
        }        
        
    }
    // set the raw to Zeroes
     for (int i = 0; i <matrix.size() ; i++)
    {
        if (matrix[i][cel] == 0 && i!=row){
           for (int j = 0; j < matrix[0].size(); j++){
            matrix[i][j] = 0;
            }
        }        
        
    }
    // set the sign row cel to Zeroes
    for (int i = 0; i < matrix[0].size(); i++)
    {
       matrix[row][i] = 0;
    }
    for (int i = 0; i < matrix.size(); i++)
    {
       matrix[i][cel] = 0;
    }

      
        
    }
};

