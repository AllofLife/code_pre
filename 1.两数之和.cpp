/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
     {
        unordered_map<int,int> map_nums;
        vector<int> res;
        for(int i = 0;i < nums.size();++i){
            // 先遍历一遍数组,建立hashmap_nums映射
            map_nums[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            // cout<< nums[i]<<endl;
            int t = target - nums[i];
            // 哈希表查找是o(1)复杂度
            if(map_nums.count(t) && map_nums[t] != i ){
                // 结果返回
                res.push_back(i);
                res.push_back(map_nums[t]);
                break ;   

            }
               
            
            /* code */
        }
        return res;
        
        
    }
};

