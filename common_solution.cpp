#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<stack>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    };
class  Solution
{
private:
   
public:
     Solution(/* args */ );
    ~ Solution();
    bool judge(char top,char newchar){
        if(top == '(' && newchar == ')'){
            return true;
        }
        else if(top == '[' && newchar == ']')
        {
            return true;
        }
        else if(top == '{' && newchar == '}')
        {
            return true;
        }
        return false;
        
        
            
    };
    bool isValid(string s) {
        // stack<char> s1;
        stack<char> s1;
        // s1.push();
        // for (string::iterator it = s.begin(); it != s.end(); it++)
        // {
            
        // }
        int i = 0;
        while (!s.empty())
        {
            if (s1.empty())
            {
                s1.push(s.at(0));
                s.erase(0,1);
            }
            else
            {
                if (judge(s1.top(),s.at(0)))
                {
                    s1.pop();
                    s.erase(0,1);
                }
                else 
                {
                    s1.push(s.at(i));
                    s.erase(0,1);
                }
            // s1.push(s.at(i));
            // s.erase(i);
            // if (judge(s1.top(),s.at(i)))
            // {
            //     s1.pop();
            //     s.erase(i);
            // }
            // else 
            // {
            //     s1.push(s.at(i));
            //     s.erase(i);
            // }
                
                
            }
            
            // i++;
            
        }
        if (s.empty() && s1.empty())
        {
            return true;
        }
        // if(!s.empty()){
        //     cout<<"s 不为空 "<<s.at(0)<<endl;
        // }
        // if(!s1.empty()){
        //     cout<<"s1 不为空"<<s1.size()<<endl;
        // }
        return false;
        
        
    
        // if (s.empty())
        // {
        //     return false;
        // }
        

    }
};
 Solution:: Solution(/* args */)
{

}

 Solution::~ Solution()
{

}

int main(int argc,char** argv){
    
    cout<<"20 有效的括号"<<endl;
    string stest = "() []{}";
    Solution s;
    
    if(s.isValid(stest)){
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    // stest.erase(0,1);
    // // stest.substr(0,0);
    // // stest.erase(1);
    // // stest.erase(2);
    // if (stest.empty())
    // {
    //     cout<<"stest 为空"<<endl;
    // }else
    // {
    //     cout<<"stest 不为空"<<stest<<endl;
    // }
    
    
    
   
    return 0;
}
