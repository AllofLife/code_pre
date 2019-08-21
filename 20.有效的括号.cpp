/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
class Solution {
public:
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
        if (s.size()%2 != 0)
        {
            return false;
        }
        
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

