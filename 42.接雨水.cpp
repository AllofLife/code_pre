/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
class Solution {
public:
  //    int trap(vector<int>& height) {
//        int ans = 0;
//        for (int i = 1; i < height.size(); i++)
//        {
//            int max_left = 0,max_right = 0;
//            for (int j = i; j >= 0; j--)
//            {
//                max_left =  max(max_left,height[j]);
//            }
//            for (int j = i; j < height.size(); j++)
//            {
//               max_right = max(max_right,height[j]);
//            }
           
//            ans += min(max_left,max_right) - height[i];
//        }
       
//         return ans;
//     }
//  int trap(vector<int>& height) {
//     // 存储每一个元素的左边最大和右边最大 三次循环
//     if (height.size() == 0)
//     {
//         return 0;
//     }
//     int size = height.size();
//     int ans = 0;
//     vector<int> left(size),right(size);
//     // 初始化
//     left[0] = height[0]; 
//     right[size - 1] = height[size - 1];

//     for (int i = 1; i < size; i++)
//     {
//         left[i] = max(height[i],left[i - 1]);
//     }
    
//     for (int i = size - 2; i >= 0; i --)
//     {
//        right[i] = max(height[i],right[i + 1]);
//     }
//     for (int i = 0; i < size; i++)
//     {
//        ans += min(left[i],right[i]) - height[i];
//     }
    
//     return ans;
//     }
    int trap(vector<int>& height) {
        //用栈来解决
        if (height.size() == 0)
        {
            return 0;
        }
        
        int ans = 0;
        stack<int> st;
        int current = 0;
        while (current < height.size())
        {
            while (!st.empty() && height[current] > height[st.top()])
            {
               int top = st.top();
               // 弹出当前元素 找到左边界
               st.pop();
               if (st.empty())
               {
                   break;
               }
               int distance = current - st.top() -1;
               int detla = min( height[current],height[st.top()] ) - height[top];
                ans += detla * distance;
            }

            
           st.push(current++);
        }
        
        return ans;
    
    }
    
    
};

