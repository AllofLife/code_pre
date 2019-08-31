/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
class Solution {
public:
    // int jump(vector<int>& nums) {
    //     int steep = 0;
    //     int jumpmax = 0;
    //     int end =0;
    //     int size = nums.size();
    //     for (int i = 0; i < size -1 ; i++)
    //     {
    //        jumpmax = max(nums[i] + i,jumpmax);
    //        if (i == end )
    //        {
    //            end = jumpmax;
    //            steep++;
    //         if (jumpmax >= size -1)
    //             {
    //                break;
    //             }
    //        }
           
           
    //     }
        
    //     return steep;

        
    // }
     int jump(vector<int>& nums) {
          int res = 0, n = nums.size(), last = 0, cur = 0;
          for (int i = 0; i < n - 1; ++i) {
              cur = max(cur, i + nums[i]);
              if (i == last) {
                  last = cur;
                  ++res;
                 if (cur >= n - 1) break;
             }
         }
         return res;
     }
};

