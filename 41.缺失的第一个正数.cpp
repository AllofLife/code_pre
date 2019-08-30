/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] != i +1)
            {
               if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[ nums[i] -1])
            {
                break;
            }
            int tmp = nums[i] -1;
            nums[i] = nums[tmp];
            nums[tmp] =  tmp + 1;
            }
            
            
            
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i +1)
            {
              return i+1;
            }
            
        }
        return nums.size() + 1;
        
        
        
    }
};

