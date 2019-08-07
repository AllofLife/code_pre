/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
class Solution {
public:
     string longestCommonPrefix(vector<string>& strs) {
     int islength = strs.size();
     if(islength==0)
        return "";
     if(islength==1)
        return strs[0];
    //  cout<<islength<<endl;
     int iSmail = 65535;
     for (int i = 0; i < islength; i++)
     {
    //    cout<<strs[i].length()<<endl;
       if (strs[i].length() < iSmail)
       {
         iSmail = strs[i].length();
       }
     }
    //  cout<<"iSmail \t"<<iSmail<<endl;
    //  cout<<"islength \t"<<islength<<endl;
     string sLarge;
     int j = 0;
     int i = 0;
     
     while ( j < iSmail )
     {
       char cCommon = strs[0][j];
       // 对每个字符串做相同的判断
       for (i = 1; i < islength; i++)
     {
    //    cout<<"cCommon\t"<<cCommon<<"\t"<<strs[i][j]<<endl;
       if (strs[i][j]!=cCommon)
       {
        //  cout<<"!="<<endl;
          return sLarge;
       }
       else 
       {
         if(i + 1 == islength){
            sLarge.push_back(cCommon);
         }
         
         //sLarge.substr(cCommon);
       }
       

       
     }
     j++;
     
    //  cout<<"sLarge \t"<<sLarge<<endl;
     
      
     }
     
     return sLarge;
        
    }
};

