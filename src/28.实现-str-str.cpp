/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */
// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle){
        int m = haystack.size();
        int n = needle.size();
        if (m == 0 && n == 0)
        {
            return 0;
        }
        if (m == 0 )
        {
            return -1;
        }
        if(n == 0)
        {
            return 0;
        }
        int index = 0;
        for (int i = 0; i < m; i++)
        {
            if(haystack[i] == needle[index]){
                index++;
            }else
            {
                i = i - index ;
                index = 0;
                
            }
            if(index == n ){
                return i - index + 1;
            }
        }
        
        
        return -1;
    }
    
};
// @lc code=end

