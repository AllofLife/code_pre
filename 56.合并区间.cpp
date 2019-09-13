/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 记录 区间首先要排序 然后在判断结果容器最后一个的区间的尾巴跟当前区间的头的大小关系
        // 如果后者大 那么这个区间直接进入结果容器
        // 否则 结果更新结果容器最后一个区间的尾巴 更新值为当前值和当前区间尾巴中最大的那一个
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
};

