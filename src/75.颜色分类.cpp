/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() == 0 ){
            return ;
        }
        // vector<int> count{0,0,0};
        // for(int i = 0;i < nums.size(); i++){
        //     count[nums[i]]++;
        // }
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if(count[0] > 0)
        //     {
        //         nums[i] = 0;
        //         count[0]--;
        //         continue;
        //     }
        //     if(count[1] > 0)
        //         {
        //             nums[i] = 1;
        //             count[1]--;
        //             continue;
        //         }
        //     if(count[2] > 0)
        //         {
        //             nums[i] = 2;
        //             count[2]--;
        //             continue;
        //         }
        //     }
        
        int p1 = 0;
        int p2 = nums.size() - 1;
        int curr = 0;
        while (curr <= p2)
        {
            if(nums[curr] == 0){
             swap(nums[curr++],nums[p1++]);
            }
            else if(nums[curr] == 2){
                swap(nums[curr],nums[p2--]);
            }
            else
            {
                // 等于1的情况
                curr++;
            }
            
        }
        
    }
};
// @lc code=end

