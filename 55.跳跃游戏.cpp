/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
           int max = 0;
           int currentMax = 0;
           int i = 0;
           while (i < size  &&  max < size - 1 )
           {
               currentMax = i + nums[i];
               if (currentMax >= max)
               {
                   max = currentMax;
               }
               if (max >= i + 1 || nums[i] > 0)
               {
                   i++;
               }
               else
               {
                   break;
               }
               
               
               
               
           }
           if (max >= size - 1)
           {
               return true;
           }
           
           
        return false;
    }
};

