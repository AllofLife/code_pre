/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int>  ans;
        if (matrix.empty())
        {
            return ans;
        }
         
        // vector<vector<int>> vv_bool;
        // 调试真的好难呀
        int R_size = matrix.size(), C_size = matrix[0].size();
        // cout<<R_size<<C_size<<endl;
        bool vv_bool[R_size][C_size] ;
        int r = 0,c = 0;
        int dic_r[4] = {0,1,0,-1};
        int dic_c[4] = {1,0,-1,0};
        int det = 0;
        // 前进的方向
        for (int i = 0; i < R_size * C_size; i++)
        {
            // cout<<matrix[r][c]<<" i "<<i<<endl;
            ans.push_back(matrix[r][c]);
            vv_bool[r][c] = true;
            int cr = r + dic_r[det];
            int cc = c + dic_c[det];
            // cout<<"det "<<det<<" cr "<<cr<<" cc "<<cc<<endl;
            // if (vv_bool[cr][cc])
            // {
            //     cout<<" true"<<endl;
            // }
            // else
            // {
            //     cout<<"false"<<endl;
            // }
            
            
            // 确保 matrix[r][c] 没有超出范围
            if (0 <= cc && cc < C_size && 0 <= cr && cr < R_size  && !vv_bool[cr][cc])
            {
                
                // 还在范围内就继续直走
                r = cr;
                c = cc;
                // cout<<" r " <<r<<" c "<<c<<endl;

            }
            else
            {
                // cout<<"转弯"<<endl;
                // 不在范围内就转个弯
                det = (det + 1) % 4;
                // cout<<" else det "<<det<<endl;
                r = r + dic_r[det];
                c = c + dic_c[det];
                // cout<<" r " <<r<<" c "<<c<<endl;

            }
            
            
        }
        
        return ans;
    }
};

