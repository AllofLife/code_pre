/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int freq = 1;
        for (int  i = 1; i < nums.size(); i++)
        { 
            if(nums[i] == nums[i - 1]){
                freq++;
            }
            else
            {
                freq = 1;
            }
            if(freq > 2){
                nums.erase(nums.begin() + i - 1);
                freq = 2;
                i--;
            }
            
        }
        return nums.size();
        
    }
};
// @lc code=end

