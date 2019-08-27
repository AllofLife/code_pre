/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0)
        {
            return vector<int> {-1,-1};
        }
        if (nums.size()==1)
        {
            if (nums[0]==target)
            {
              return vector<int> {0,0};
            }
            
            
            return vector<int> {-1,-1};
        }
        int first = 0;
        int last = nums.size();
        int mid = (first + last) / 2;
        bool findOk = false;
        int loca = 0;
         int l = 0,r = 0;
         // 找左边界
         while (first < last)
         {
           if (nums[mid] == target)
           {
               last = mid;
           }
           else if (nums[mid] > target)
           {
               last = mid;
           }
           else if(nums[mid] < target)
           {
               first = mid + 1;
           }
            mid = (first  + last ) / 2;
           
         }
         l = first;

         // 找右边界
         first = 0;
         last = nums.size();
         mid = (first + last) / 2;
         while (first < last)
         {
           if (nums[mid] == target)
           {
               first = mid + 1;
           }
           else if (nums[mid] > target)
           {
               last = mid;
           }
           else if(nums[mid] < target)
           {
               first = mid + 1;
           }
            mid = (first  + last ) / 2;
           
         }
         r = last -1;
        //  cout<<"first "<<l<<" last: "<<r<<endl;
           if (r < l)
        {
            return vector<int> {-1 ,-1};
        }
        return vector<int> {l ,r};
        
    }
};

