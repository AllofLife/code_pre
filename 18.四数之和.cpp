/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
class Solution {
public:
       vector<vector<int>> fourSum(vector<int>& nums, int target) {
         vector<vector<int>> vvvtest;
    //    先进性有效性检查
       int  len = nums.size();
       if (len == 0 || len < 4)
       {
           return vvvtest;
       }
       else if(nums.size() == 4)
       {
           if (nums[0] + nums[1] + nums[2] +nums[3] == target)
           {
               vvvtest.push_back({nums[0],nums[1],nums[2],nums[3]});
               return vvvtest;
           }
           else
           {
               return vvvtest;
           }
           
           
       }
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            
            // if (nums[i] > target )
            // {
            //     break;
            // }
            for (int j = i + 1 ; j < nums.size(); j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                // if (nums[j] + nums[i] > target)
                // {
                //     break;
                // }
                
                
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    if (nums[i] + nums[j] + nums[left] + nums[right] > target)
                    {
                        right--;
                    }
                    else if (nums[i] + nums[j] + nums[left] + nums[right] < target)
                    {
                       left++;
                    }
                    else
                    {
                        vvvtest.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left -1])
                        {
                             left++;
                        }
                        while (left < right && nums[right] == nums[right + 1])
                        {
                             right--;
                        }

                    }
                    
                    
                }
                
            }
            
          
        }
        return vvvtest;
        
    }
};

