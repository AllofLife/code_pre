/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
class Solution {
public:
    void traverse(TreeNode* root,vector<int>& result)
    {
        if(root == nullptr)
        {
            return;
        }
        traverse(root->left,result);
        result.push_back(root->val);
        traverse(root->right,result);
    }
    vector<int> inorderTraversal_re(TreeNode* root) 
    {
    
        vector<int> result;
        
        traverse(root,result);
        return result;
        
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return {};
        }
        vector<int> result;
        stack<TreeNode*> sta;
    
        TreeNode* cur  = root;
        while (cur != nullptr || !sta.empty()  )
        {
            // 找到当前子树的最左边叶节点的左节点
            while (cur != nullptr)
            {
               sta.push(cur);
               cur = cur->left;
            }
            // 取出当前子树的最左边的叶子节点
            cur = sta.top();
            // 中序访问
            result.push_back(cur->val);
            // 访问完了之后 将叶子节点弹出
            sta.pop();
            // 叶子节点的右子树
            cur = cur->right;
            
        }
        return result;
    }
};
// @lc code=end

