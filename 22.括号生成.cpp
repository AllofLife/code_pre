/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
class Solution {
public:
    void backtack(vector<string> &vresult,string scurrent, int open,int close,int max){
        if (open > max || close > max || close > open){
            return ;
        }
        if (open == max && close == max)
        {
            vresult.push_back(scurrent);
            return;
        }
        
       
        backtack(vresult,scurrent+"(",open+1,close,max);
        backtack(vresult,scurrent+")",open,close+1,max);
        return ;

            
            
            
     
        
    }
     vector<string> generateParenthesis(int n) {
     vector<string> result;
     backtack(result,"",0,0,n);
      return result;


    }
};

