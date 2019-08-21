/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int s1 = nums1.size();
      int s2 = nums2.size();
      int left = (s1 + s2 + 1) / 2;
      int right = (s1 + s2 + 2) / 2;

      //return 0.0;
      return (finKth(nums1,0,nums2,0,left) + finKth(nums1,0,nums2,0 ,right))/2.0;

        
    }
    int finKth(vector<int>& nums1,int i,vector<int>& nums2,int j,int k){
        if(i >= nums1.size()) return nums2[j + k - 1];
        if(j >= nums2.size()) return nums1[i + k - 1];
        
        if(k == 1) 
            return min(nums1[i],nums2[j]);
        int mid_val1 = (i + k /2 - 1 < nums1.size() ? nums1[i + k / 2 - 1] : __INT_MAX__);
        int mid_val2 = (j + k /2 - 1 < nums2.size() ? nums2[j + k / 2 - 1] : __INT_MAX__);
        if(mid_val1 < mid_val2)
            return finKth(nums1,i + k / 2,nums2,j,k - k / 2);
        else
        {
            return finKth(nums1,i,nums2,j + k / 2,k - k / 2);
        }
        
 
    }
};

