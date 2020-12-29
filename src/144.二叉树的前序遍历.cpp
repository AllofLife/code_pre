/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<vector>
#include<stack>
using namespace std;

// struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode() : val(0), left(nullptr), right(nullptr) {}
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  };
class Solution {
public:
    void traverse_first_order(TreeNode* root,vector<int>& ans)
    {
        if(root == nullptr)
        {
            return ;
        }
        ans.push_back(root->val);
        traverse_first_order(root->left,ans);
        traverse_first_order(root->right,ans);

    }
    vector<int> preorderTraversal(TreeNode* root)
    {
        if(root == nullptr)
        {
            return {};
        }
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode* cur = root;
        while (cur != nullptr || !s.empty())
        {
            while (cur != nullptr)
            {
                s.push(cur);
                ans.push_back(cur->val);
                cur = cur->left;
            }
            // // 将空的 节点 出栈
            // s.pop();  
            // 取出 栈顶元素
            cur = s.top() ;
            // 将根节点出栈
            s.pop();
            // 访问右子树
            cur = cur->right;
        }
        return ans;
        
    }
    vector<int> preorderTraversal_traverse(TreeNode* root) {
        if(root == nullptr)
        {
            return {};
        }
        vector<int> ans;
        traverse_first_order(root,ans);
        return ans;
    }
};
// @lc code=end

