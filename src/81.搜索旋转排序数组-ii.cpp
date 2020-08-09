/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() ==  0){
            return false;
        }
        if(nums[0] == target)
        { return true; } 
        for (int i = 1; i < nums.size(); i++) 
        { 
            if(nums[i] == target) 
            return true;
             else if ( nums[i] < nums[i - 1] && target >nums[i - 1]  ) 
             { break; } 
        } 
        return false;
    }
};
// @lc code=end

