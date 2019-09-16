/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool plus = true;
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--)
        {
           if ((digits[i] + 1) / 10)
           {
               digits[i] = digits[i] + 1;
               if (digits[i] >= 10 )
               {
                  
                   digits[i] = 0;
                   plus =true;
               }
               else
               {
                   return digits;
               }
               
               
           }
           else
           {
               if (plus)
               {
                     digits[i] = digits[i] + 1;
                     plus = false;
                     return digits;
               }
               
            
           }
          
        }
           
           
           
        
         if (plus)
           {
            //    digits.insert(digits.begin(),1);
            digits[0] = 1;
            digits.push_back(0);
            }
        return digits;
        

        
    }
};

