/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
class Solution {
   private:
   vector<string> res;
   const string str_index[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    public:
    void funCallback(string &digits,string &str,int index){
        if(digits.size() == str.size()){
             res.push_back(str);
             return;
        }
        string tmp = str_index[digits[index] - '0'];
        index += 1;
        for (int i = 0; i < tmp.size(); i++)
        {
            str+= tmp.at(i);
            funCallback(digits,str,index);
            str.pop_back();
        }
        
    };
    vector<string> letterCombinations(string digits) {
        res.clear();
        if (digits.empty())
        {
           return res;
        }
        string str;
        funCallback(digits,str,0);
        return res;
        
    }
};

