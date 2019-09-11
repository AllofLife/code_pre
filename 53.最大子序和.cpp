/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int sum = 0;
        int ans = nums[0];
        for(int i = 0;i <nums.size() ;i++){
            // sum 是前一个数字
            if(sum > 0){
                sum += nums[i];
            }
            else
            {
                sum = nums[i];
            }
            ans = max(sum,ans);
        }
        return ans;
    
    }
};

