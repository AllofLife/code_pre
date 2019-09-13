/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       
        
        vector<vector<int>> vvtest;
        vvtest.resize(n);
         if (n == 1)
        {
            vvtest[0].push_back(1);
           return vvtest;
        }
        
        
        for (int i = 0; i < n; i++)
        {
           for (int j = 0; j < n; j++)
           {
               vvtest[i].push_back(0);
           }
           
        }

        int R_size = n, C_size = n;
        // cout<<R_size<<C_size<<endl;
        int vv_bool[R_size][C_size] = {0,0} ;
        for (int i = 0; i < R_size; i++)
        {
           for (int j = 0; j < C_size; j++)
           {
            //   cout<<vv_bool[i][j]<<" ";
            vv_bool[i][j] = 0;
           }

           
        }
       
        
        int r = 0,c = 0;
        int dic_r[4] = {0,1,0,-1};
        int dic_c[4] = {1,0,-1,0};
        int det = 0;
        // 前进的方向
        for (int i = 0; i < R_size * C_size; i++)
        {
            // cout<<matrix[r][c]<<" i "<<i<<endl;
            // ans.push_back(matrix[r][c]);
            vv_bool[r][c] = i + 1;
            vvtest[r][c] = i + 1;
            int cr = r + dic_r[det];
            int cc = c + dic_c[det];
            // cout<<"det "<<det<<" cr "<<cr<<" cc "<<cc<<endl;
            
            
            // 确保 matrix[r][c] 没有超出范围
            if (0 <= cc && cc < C_size && 0 <= cr && cr < R_size  && vv_bool[cr][cc] == 0)
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
        
        return vvtest;
        
    }
};

