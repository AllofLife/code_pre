/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
        {
           return 0;
        }
        
        
        int i = 0;
        int j = i + 1;
        int vsize = nums.size();
        while (j < vsize)
        {
            if (nums[i] == nums[j])
            {
               j++;
            }
            else
            {
                i++;
                nums[i] = nums[j];
                j++;
            }
            
            
        }
        
        
       
        
        return i + 1;
    }
};

