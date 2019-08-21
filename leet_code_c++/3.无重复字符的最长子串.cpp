/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ia_map[256] = {0};
        int ires = 0,ileft = 0;
        for(int i = 0; i < s.size(); ++i){
            if(ia_map[s[i]] == 0 || ia_map[s[i]] < ileft){
                ires = max(ires,i - ileft + 1);
                //ires = i - ileft + 1;
            }
            else
            {
                ileft = ia_map[s[i]];
            }
            ia_map[s[i]] = i + 1;
        }
        return ires;


        
    }
};

