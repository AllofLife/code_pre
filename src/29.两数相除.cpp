/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
      int divide(int dividend, int divisor) {
         if(divisor == 1) return dividend;
        if(divisor == -1){
            if(dividend>INT_MIN) return -dividend;// 只要不是最小的那个整数，都是直接返回相反数就好啦
            return INT_MAX;// 是最小的那个，那就返回最大的整数啦
        }
        if(abs(dividend) < abs(divisor))
            return 0;
        int  n = 0;
        int divisors = divisor;
        if(divisor > 0 && dividend > 0){
        if(divisor == dividend)
            return 1;
        else
        {
            n = 0;
            while (divisors < dividend)
            {
                divisors += divisor;
                n++;
            }
            
        }
        
        }
        else if (divisor < 0 && dividend > 0)
        {
            n = 0;
            while ( abs(divisors) <= dividend)
            {
                divisors += divisor;
                n--;
            }
            
        }
        else if (divisor > 0 && dividend < 0)
        {
            
            n = 0;
            while ( divisors <= abs(dividend))
            {
                divisors += divisor;
                n--;
            }
        }
        
        else
        {
            n = 0;
            while ( divisors >= dividend)
            {
                divisors += divisor;
                n++;
            }
        }
        
        
        return n;
        
    }
};
// @lc code=end

