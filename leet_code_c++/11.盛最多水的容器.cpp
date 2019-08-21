/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0,right = height.size() - 1;
        int max = 0;
        int rmax = 0;
        while (left != right)
        {
            if(height[left] > height[right]){
                max = (right - left) * height[right];
                right--;
            }
            else
            {
                max = (right - left) * height[left];
                left++;
            }
            if (max > rmax)
            {
                rmax = max;
            }
            
           
        }
        // cout<<"left "<<height[left]<<"left_index "<<left<<" right "<<height[right]<<"  right_index "<<right<<endl;
            return rmax;
        
    }
};

