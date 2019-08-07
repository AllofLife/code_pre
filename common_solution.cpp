#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<unordered_map>

using namespace std;

class  Solution
{
private:
    /* data */
public:
     Solution(/* args */ );
    ~ Solution( );
   string longestCommonPrefix(vector<string>& strs) {
     if (strs.empty())
     {
       return "";
     }
     
     for (int i = 0; i < strs[0].size(); i++)
     {
       for (int j = 1; j < strs.size(); j++)
       {
                if (strs[j][i]!=strs[0][i])
                {
                  return strs[0].substr(0,i);
                }
                
       }
       
     }
     return strs[0];
     
        
    }
};
 Solution:: Solution(/* args */)
{

}

 Solution::~ Solution()
{

}
int main(int argc,char** argv){
    
    cout<<"14 最长公共前缀"<<endl;
    vector<string> VsTest;
    VsTest.push_back("dog");
    VsTest.push_back("dracecar");
    VsTest.push_back("dcar");
    Solution s;
    cout<<s.longestCommonPrefix(VsTest)<<endl;
    cout<<endl;

    return 0;
}
