/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
class Solution {
public:
    int reverse(int x) {
        int pop = 0,ans = 0;
        while (x)
        {
            pop = x % 10;
            x = x / 10;
            if(ans > __INT32_MAX__ / 10 || (ans == __INT32_MAX__ / 10 &&  pop > 7))
                return  0;
            if(ans < - (__INT32_MAX__ - 1) / 10   || (ans ==  - (__INT32_MAX__ - 1 ) / 10 &&  pop < -8))
                return 0;
            ans = ans * 10 + pop;
            
        }
        return ans;
        
        
    }
};

