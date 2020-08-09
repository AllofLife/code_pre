/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    
    vector<vector<int>> subsets(vector<int>& nums) {
        // vector<vector<int>> vreturn(1);
        vector<vector<int> > vreturn(1);
        // vreturn.push_back(vector<int>([]));
        // if(nums.size() == 0){
            
        //     return vreturn;
        // }
        int n = nums.size();
        // 
        for (int i = 0; i < nums.size(); i++)
        {
            // vreturn.push_back(nums[i]);
            n = vreturn.size();
            for (int j = 0; j < n ; j++)
            {
                vector<int> tmp = vreturn[j];
                tmp.push_back(nums[i]);
                vreturn.push_back(tmp);
            }
            
            
        }
        
        return vreturn;


        // vector<vector<int> > res(1);
        // for(int i=0;i<nums.size();i++){
        //     int cnt=res.size();
        //     for(int j=0;j<cnt;j++){
        //         vector<int> tmp=res[j];
        //         tmp.push_back(nums[i]);
        //         res.push_back(tmp);
        //     }
        // }
        // return res;


        
    }
};
// @lc code=end

