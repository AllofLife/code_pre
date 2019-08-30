/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
class Solution {
public:
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

