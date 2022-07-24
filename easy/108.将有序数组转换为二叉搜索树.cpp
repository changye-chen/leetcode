/*
 * @Author: czh 18782812147@163.com
 * @Date: 2022-07-23 23:53:45
 * @LastEditors: czh 18782812147@163.com
 * @LastEditTime: 2022-07-24 00:35:41
 * @FilePath: /.leetcode/108.将有序数组转换为二叉搜索树.cpp
 * @Description:
 *
 * Copyright (c) 2022 by czh 18782812147@163.com, All Rights Reserved.
 */
/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (77.02%)
 * Likes:    1095
 * Dislikes: 0
 * Total Accepted:    281.1K
 * Total Submissions: 364.9K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡
 * 二叉搜索树。
 *
 * 高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1
 * 」的二叉树。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-10,-3,0,5,9]
 * 输出：[0,-3,9,-10,null,5]
 * 解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,3]
 * 输出：[3,1]
 * 解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums 按 严格递增 顺序排列
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        return sortedArrayToBST(nums, low, high);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums, int low, int high) {
        if (low > high)
            return nullptr;
        int mid = low + (high - low) / 2;
        if (mid == high) {
            TreeNode* node = new TreeNode(nums[mid]);
            return node;
        }
        TreeNode* node =
            new TreeNode(nums[mid], sortedArrayToBST(nums, low, mid - 1),
                         sortedArrayToBST(nums, mid + 1, high));
        return node;
    }
};
// @lc code=end
int main(int argc, char const* argv[]) {
    vector<int> nums = {1};
    Solution s;
    s.sortedArrayToBST(nums);
    return 0;
}
