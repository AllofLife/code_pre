/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    
     
    vector<vector<char>> cboard;
    int n = 3;
    int N = n * n;
    int rows [9][10];
    int colums [9][10];
    int boxes [9][10];
    bool suduSloved = false;
    bool couldPlaceNumber(int d,int row,int col){
        int idx = (row / 3) * 3 + (col / 3);
        return rows[row][d] + colums[col][d] + boxes[idx][d] == 0;
    }
    void  placeNumber(int d,int row,int col){
        int  idx = (row / 3) * 3 + (col / 3);
        colums[col][d] ++;
        rows[row][d] ++;
        boxes[idx][d] ++;
        cboard[row][col]  = (char) d + '0';
    }
    void placeNextNumber(int row,int col){
        if(row == 8 && col == 8){
            suduSloved = true;
        }
        else
        {
            // 下一行 第一个元素
            if(col == 8){
            backtrack(row+1,0);
        }
        else
        {
            backtrack(row,col+1);
        }
        
        }

    }
    void removeNumber(int d,int row,int col){
        int  idx = (row / 3) *3 + (col / 3);
        colums[col][d] --;
        rows[row][d] --;
        boxes[idx][d] --;
        cboard[row][col]  = '.';
    }
    void backtrack(int row,int col){
        if(cboard[row][col] == '.') {
            for (int i = 1; i < 10; i++)
            {
                if(couldPlaceNumber(i,row,col)){
                        placeNumber(i,row,col);
                        placeNextNumber(row,col);
                        if(!suduSloved){
                        removeNumber(i,row,col);
                    }
                }
                
                
            }
        }
        else
        {
            placeNextNumber(row,col);
        }
        
    }


     void solveSudoku(vector<vector<char>>& board) {
        cboard = board;
        
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                placeNumber((int)(board[i][j] - '0'),i,j);
            }
            
        }
        backtrack(0,0);
        board = cboard;
        
    }
};
// @lc code=end

