/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
class Solution {
public:
    bool isPalindrome(int x) {
        // 处理负数的情况
        if(x<0)
            return false;
        int last = 0;
        if(x % 10 == 0 && x != 0) 
            return false;
        while (last <= x)
        {
            if(x == last)
                return true;
            
            last = last * 10 + x % 10;
            if(x == last)
                return true;
           
            x = x / 10;
        } 
        return false;
    }
};

