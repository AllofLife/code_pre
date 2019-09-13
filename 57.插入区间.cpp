/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */
class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
            vector<vector<int>> vvResult ;
            int begin = 0;
            int size = intervals.size();
            if (size < 1)
            {
                return vvResult;
            }
            sort(intervals.begin(),intervals.end());
    
            while (begin <= size -1 )
            {
                if(vvResult.empty() || (vvResult.end() - 1)->at(1) < intervals[begin][0] ){
                    vvResult.push_back(intervals[begin]);
                }      
                else
                {
                    (vvResult.end() - 1)->at(1) = max((vvResult.end() - 1)->at(1),intervals[begin][1]);
                }
                          
                begin++;
            }
            
            

return vvResult;
        
    }
     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
        // return {};
    }

};

