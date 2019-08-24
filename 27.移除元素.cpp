/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
                int i = 0;
        int j = 0;
        int vsize = nums.size();
        while (j < vsize)
        {
            // cout<<nums[j]<<endl;
            if (nums[j]!=val)
            {
              nums[i] = nums[j];
               i++;
              
            }
            j++;
            
            
        }
        
        
       
        
        return i  ;
    
    }
};

