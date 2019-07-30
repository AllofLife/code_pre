/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
class Solution {
public:
    int myAtoi(string str) {
        // 去掉开头的空格
        str.erase(0,str.find_first_not_of(" "));
        if(str.size() < 1)
            return 0;
        long int t = 0;
        int i = 0;
        bool f = false;
        if(str[0] == '-'){
            f = true;
            str.erase(0,1);
        }
        else if(str[0] == '+'){
            f = false;
            str.erase(0,1);
        }
        else if(str[i] >= '0' && str[i] <= '9'){
            f = false;
        }
        else
        {
            return 0;
        }
        // 获取数字的长度
        for(;i < str.size();){
            if(str[i] >= '0' && str[i] <= '9')
                i++;
            else
            {
                break;
            }
            
        }
        int j  = i;
        for (; i > 0;i--){
            // 还原数字
            t += (str[i - 1] - '0') * pow(10,j - i);
        }
        
        if(f && t > __INT32_MAX__) 
            return (-1 * __INT32_MAX__ - 1) ;
        if(!f && t < 0)
            return __INT32_MAX__;
        if(t >= __INT32_MAX__)
            if(f)
                if (t == __INT32_MAX__ )
                {
                    return -1 *__INT32_MAX__;
                }
                else
                {
                   return -1 * (__INT32_MAX__ + 1);
                }              
            else
            {
                return __INT32_MAX__;
            }
            
        if(t < (signed int) 0x80000000)
            return (-1 * __INT32_MAX__ - 1) ;
            
                
        
        t *= f?-1:1;
        
        return t;
      
        
        
    }
};

