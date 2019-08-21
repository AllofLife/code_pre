/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
class Solution {
public:
      int threeSumClosest(vector<int>& nums, int target) {
       int min_sum,current_sum;      
       sort(nums.begin(),nums.end());
       for (int i = 0; i < nums.size(); i++)
       {

       
           int r = nums.size() - 1;
           int l = i + 1;
           if (i == 0 && l == 1 && r == (nums.size() - 1))
            {
                min_sum = nums[i] + nums[l] + nums[r];
            }
            
           while (l < r)
           {
               current_sum = nums[i] + nums[l] + nums[r];
               if (current_sum == target )
               {
                   return current_sum;
               }
               if (abs(current_sum - target) < abs(min_sum - target) )
               {
                  min_sum = current_sum;
               }
               if (current_sum < target)
               {
                    l++;
               }
              else if (current_sum > target)
              {
                 r--;
              }
            else
            {
                return current_sum;
            }
               
               
               
               
           }
          
            
           
       }
       
        return min_sum;
    }
};

