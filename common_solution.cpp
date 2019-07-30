#include<iostream>
#include<vector>
#include<math.h>
#include<string>
using namespace std;

class  Solution
{
private:
    /* data */
public:
     Solution(/* args */);
    ~ Solution();
    bool isMatch(string s, string p) {
        int m = s.size(),n = p.size();
        vector<vector<bool>> dp(m + 1,vector<bool>(n + 1,false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j > 1 && p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.' ) && dp[i - 1][j]);
                    
                }
                else
                {
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
                
                
            }
            
        }
        
        return dp[m][n];
        //   int m = p.length() + 1; int n = s.length() + 1;
        // //vector<vector<bool>>dp(m,vector<bool>(n));
        // bool **dp=NULL;
        // dp = new bool *[m];
        // for (int i = 0; i < m; i++)
        // {
        //     dp[i] = new bool[n];
        // }
 
        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (i == 0)//初始化
        //         {
        //             if (j == 0)dp[i][j] = true;
        //             else dp[i][j] = false;
        //         }
        //         else if (j == 0)
        //         {//i只可能是1开始
        //             if (p[i - 1] != '*')dp[i][j] = false;
        //             else dp[i][j] = dp[i - 1][j] || dp[i - 2][j];////p第一个是*的，s第一个是空，短路操作不会越界，所以不能调换，细节
        //         }
        //         else
        //         {
        //             if (p[i - 1] == '.')dp[i][j] = dp[i - 1][j - 1];
        //             else if (p[i - 1] == '*')
        //             {
        //                 if (i == 1)dp[i][j] = false; //第一个是*的其他情况
        //                 else  dp[i][j] = dp[i - 2][j]
        //                                || dp[i - 1][j] 
        //                                || ((p[i-2]=='.'||p[i-2]==s[j-1])&&dp[i][j - 1]);
        //             }
        //             else dp[i][j] = ((s[j - 1] == p[i - 1] )&& dp[i - 1][j - 1]);
                    
 
        //         }
        //     }
            
        // }
        // return dp[m - 1][n - 1];

    }
};
 Solution:: Solution(/* args */)
{

}

 Solution::~ Solution()
{

}
int main(int argc,char** argv){
    // cout<<(signed int) 0x8fffffff<<endl;    
    cout<<"10 正则表达式"<<endl;
    Solution s;
   
    if(s.isMatch("aasdfasdfasdfas","aasdf.*asdf.*asdf.*asdf.*s"))
        cout<<"true";
    else
    {
        cout<< "false";
    }
    
   
    cout<<endl;

    return 0;
}
