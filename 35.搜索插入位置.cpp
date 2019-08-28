/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
class Solution {
public:
     int searchInsert(vector<int>& nums, int target) {
       if (nums.size() == 0)
       {
           return 0;
       }
       
       int low,hight;
       low = 0;
       hight = nums.size() - 1;
       int middle = (low + hight) / 2;
       while (low <= hight)
       {
           if (nums[middle] < target)
           {
              low = middle + 1;
           }
           else if(nums[middle] > target)
           {
               hight = middle -1;
           }
           else
           {
               return middle;
           }
           
          middle = (low + hight) / 2;
           
       }
        if (nums[middle] > target)
        {
           return middle;
        }
        
       return middle + 1;
        
    }
};

