/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */
class Solution {
public:
    string intToRoman(int num) {
        string result ;
        int count = 1;
        while (num)
        {
            if(num / 1000 ){
                count = num / 1000;
                for (int i = 0; i < count; i++)
                {
                     result +="M";
                }                            
                num = num - 1000 * count;
            }
            else if (num / 900)
            {
               result += "CM" ;
                num = num - 900;
            }
            else if (num / 500)
            {
               result += "D" ;
                num = num - 500;
            }
            else if (num / 400)
            {
               
                result += "CD" ;                
                num = num -  400;
            }
            else if (num / 100)
            {
                count = num / 100;
                for (int i = 0; i < count; i++)
                {
                    result += "C" ;
                }              
                num = num - 100 * count;
            }
            else if (num / 90)
            {
               
                result += "XC" ;                          
                num = num -  90;
            }
             else if (num / 50)
            {
               
                result += "L" ;                         
                num = num -  50;
            }
             else if (num / 40)
            {
                
                result += "XL" ;                      
                num = num - 40;
            }
             else if (num / 10)
            {
                count = num / 10;
                for (int i = 0; i < count; i++)
                {
                    result += "X" ;
                }              
                num = num - 10 * count;
            }
            else if (num / 9)
            {
               
                result += "IX" ;                          
                num = num -  9;
            }
             else if (num / 5)
            {
               
                result += "V" ;                          
                num = num -  5;
            }
             else if (num / 4)
            {
                
                result += "IV" ;                      
                num = num - 4;
            }
             else if (num / 1)
            {
                count = num / 1;
                for (int i = 0; i < count; i++)
                {
                    result += "I" ;
                }              
                num = num - 1 * count;
            }
            
           
            
       }
        
        
        return result;
        
    }

};

