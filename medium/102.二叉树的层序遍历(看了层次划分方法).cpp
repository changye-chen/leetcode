/*
 * @Author: czh 18782812147@163.com
 * @Date: 2022-07-23 23:26:25
 * @LastEditors: czh 18782812147@163.com
 * @LastEditTime: 2022-07-23 23:50:47
 * @FilePath: /.leetcode/102.二叉树的层序遍历.cpp
 * @Description:
 *
 * Copyright (c) 2022 by czh 18782812147@163.com, All Rights Reserved.
 */
/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (64.94%)
 * Likes:    1396
 * Dislikes: 0
 * Total Accepted:    625.9K
 * Total Submissions: 963.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。
 * （即逐层地，从左到右访问所有节点）。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[9,20],[15,7]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1]
 * 输出：[[1]]
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [0, 2000] 内
 * -1000 <= Node.val <= 1000
 *
 *
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#define PI acos(1.0)

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> all = {};
        vector<int> now = {};
        if (!root) {
            return all;
        }
        queue<TreeNode*> q;
        TreeNode* cur = root;
        TreeNode* last = root;
        TreeNode* next = nullptr;
        q.push(root);
        while (!q.empty()) {
            cur = q.front();
            now.push_back(cur->val);
            q.pop();
            if (cur->left) {
                q.push(cur->left);
                next = cur->left;
            }
            if (cur->right) {
                q.push(cur->right);
                next = cur->right;
            }
            if (cur == last) {
                vector<int> tmp = now;
                all.push_back(tmp);
                now.clear();
                last = next;
            }
        }
        return all;
    }
};
// @lc code=end
