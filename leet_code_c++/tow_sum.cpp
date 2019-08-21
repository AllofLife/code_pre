#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
// time 201907201559
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
     {
        unordered_map<int,int> map_nums;
        vector<int> res;
        for(int i = 0;i < nums.size();++i){
            // 先遍历一遍数组,建立hashmap_nums映射
            map_nums[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            cout<< nums[i]<<endl;
            int t = target - nums[i];
            // 哈希表查找是o(1)复杂度
            if(map_nums.count(t) && map_nums[t] != i ){
                // 结果返回
                res.push_back(i);
                res.push_back(map_nums[t]);
                break ;   

            }
               
            
            /* code */
        }
        return res;
        
        
    }
};

int main(int argc,char** argv){
    cout<<"two sum test"<<endl;
    vector<int> vinput_num ;
    vinput_num.push_back(11);
    vinput_num.push_back(7);
    vinput_num.push_back(2);

    
    vinput_num.push_back(15);
    int itarget_num = 9;
    Solution Tow_sum;
    vector<int>  viresult = Tow_sum.twoSum(vinput_num,itarget_num);
    // 访问容器的方法
    vector<int>::iterator vit;
    cout<<"the input nums is"<<endl;
    for(vit = vinput_num.begin();vit != vinput_num.end();vit++){
        cout<<*vit<<"\t";
    }
    cout<<"\nthe target is "<<itarget_num<<endl;
    cout<<"the result is ";
    for(vit = viresult.begin();vit != viresult.end();vit++){
        cout<<*vit<<"\t";
    }
    cout<<endl;
    return 0;



}