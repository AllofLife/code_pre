#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ia_map[256] = {0};
        int ires = 0,ileft = 0;
        for(int i = 0; i < s.size(); ++i){
            if(ia_map[s[i]] == 0 || ia_map[s[i]] < ileft){
                ires = max(ires,i - ileft + 1);
                //ires = i - ileft + 1;
            }
            else
            {
                cout<<s[i]<<endl;
                ileft = ia_map[s[i]];
            }
            ia_map[s[i]] = i + 1;
            cout<<i<<"\t"<<ileft<<s[i]<<ires<<endl;
        }
        return ires;


        
    }
};
int main(int argc,char** argv){
    cout<<"max_length_str"<<endl;
    Solution s;
    cout<<s.lengthOfLongestSubstring("tmmzuxt")<<endl;
}