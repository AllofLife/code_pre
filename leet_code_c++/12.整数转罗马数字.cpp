/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */
class Solution {
public:
     string intToRoman(int num) {
        string result;
        string dic[] ={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int int_index[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        int i = 0;
        while (i < 13 && num)
        {
            if(num/int_index[i]){
                num = num - int_index[i];
                result += dic[i];
            }
            else
            {
                i++;
            }
            
        }
        
        return result;
        
    }

};

