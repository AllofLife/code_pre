/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 * 一次扫描注意找到了从后面连续上升到下降的那个数之后 
 * 再从最后扫描一个比刚才那个数字更大的数字 把两者交换 
 * 之后把两者交换 前者之后的所有数字进行排序从小到大
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size()==0)
        {
           return ;
        }
        
        // int max_order = nums[0];
        int i  =nums.size() -2 ;

        for (; i >= 0; i--)
        {
            // 找到第一个下降的地方
            if (nums[i] < nums[i + 1])
            {
                // cout<<nums[i]<<nums[i+1]<<endl;
                break;
            }
            
        }
        if(i >= 0){
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i])
            {
               j--;
            }
            // cout<<nums[i]<<nums[j]<<endl;
            int tmp = nums[j];
            nums[j] = nums[i];
            nums[i] = tmp;
            // return;
        }
        // cout<<"i"<<i<<endl;
        // 把后面的数排序
        sort(nums.begin()+i+1,nums.end());
        
    }
};

