/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool judgeRow(vector<vector<char>>& board,int row,int cel,char value){
        for (size_t i = 0; i < 9 ; i++)
        {
            if(i != cel &&board[row][i] != '.' && board[row][i] == value  )
                return false;
        }
        return true;
        
    }
    // 列
    bool judgeCel(vector<vector<char>>& board,int row,int cel,char value){
        for (size_t i = 0; i < 9 ; i++)
        {
            if(i != row && board[i][cel] != '.' &&  board[i][cel] == value)
                return false;
        }
        return true;
        
    }
    // 判断正方形 
    bool judgeRet(vector<vector<char>>& board,int row_,int cel_,int ret,char value){
        int row = ret / 3 * 3 ;
        int cel = ret % 3 * 3;
        for (size_t i = row ; i < row + 3 ; i++)
        {
            for (size_t j = cel; j < cel + 3; j++)
            {
                if(i == row_ && j == cel_)
                    break;
                if(board[i][j] != '.' &&board[i][j] == value)
                   {
                    //    std::cout<<std::endl<<"erroro " << row_<<cel_<<i << j << ret <<std::endl;
                       return false;
                   }
            }
            
        }
        return true;
        
    }
    bool isValidSudoku(vector<vector<char>>& board) {
     int ret = 0;
        for (size_t i = 0; i < 9; i++)
        {
           for (size_t j = 0; j < 9; j++)
           {
               if(board[i][j] == '.')
                continue;
            //    std::cout << i << j;
            //    std::cout << " row ";
               if (!judgeRow(board,i,j,board[i][j]))
               {
                   return false;
               }
            //    std::cout << " cel ";
               if (!judgeCel(board,i,j,board[i][j]))
               {
                   return false;
               }
            //    std::cout << " ret ";
                ret =  i / 3 * 3 + j / 3 ;
               if (!judgeRet(board,i,j,ret,board[i][j]))
               {
                   return false;
               }
               
           }
           
        }
        return true;
        
    }
};
// @lc code=end

