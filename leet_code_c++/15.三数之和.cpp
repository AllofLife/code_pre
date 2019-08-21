/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
class Solution {
public:
      vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> vvResult;
    //    先进性有效性检查
       int  len = nums.size();
       if (len == 0 || len < 3)
       {
           return vvResult;
       }
       else if(nums.size() == 3)
       {
           if (nums[0] + nums[1] + nums[2] == 0)
           {
               vvResult.push_back({nums[0],nums[1],nums[2]});
               return vvResult;
           }
           else
           {
               return vvResult;
           }
           
           
       }
       
       sort(nums.begin(),nums.end());
       int target ;
       for (int i = 0; i < len; i++)
       {
        //    去重第一步
           if (i > 0 && nums[i] == nums[i - 1])
                continue;
           target = nums[i];
           if (target > 0)
           {
               break;
           }
           
           int l = i + 1,r = len - 1;
           while (l < r)
           {
                if (target + nums[l] + nums[r] > 0)
            {
                r--;
            }
            else if (target + nums[l] + nums[r] < 0)
            {
                l++;
            }
            else
            {
                vvResult.push_back({target,nums[l],nums[r]});
                l++,r--;
                while (l < r && nums[l] == nums[l -1])
                {
                    l++;
                }
                while (l < r && nums[r] == nums[r + 1])
                {
                    r--;
                }
            }
           }
           
           
           
           
           
       }
       
       return vvResult;
        
    }
};

