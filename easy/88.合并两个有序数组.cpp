/*
 * @Author: czh 18782812147@163.com
 * @Date: 2022-07-24 00:37:25
 * @LastEditors: czh 18782812147@163.com
 * @LastEditTime: 2022-07-24 12:12:54
 * @FilePath: /.leetcode/88.合并两个有序数组.cpp
 * @Description:
 *
 * Copyright (c) 2022 by czh 18782812147@163.com, All Rights Reserved.
 */
/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode.cn/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (52.39%)
 * Likes:    1498
 * Dislikes: 0
 * Total Accepted:    710.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n
 * ，分别表示 nums1 和 nums2 中的元素数目。
 *
 * 请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
 *
 * 注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1
 * 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m
 * 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * 输出：[1,2,2,3,5,6]
 * 解释：需要合并 [1,2,3] 和 [2,5,6] 。
 * 合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums1 = [1], m = 1, nums2 = [], n = 0
 * 输出：[1]
 * 解释：需要合并 [1] 和 [] 。
 * 合并结果是 [1] 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums1 = [0], m = 0, nums2 = [1], n = 1
 * 输出：[1]
 * 解释：需要合并的数组是 [] 和 [1] 。
 * 合并结果是 [1] 。
 * 注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0
 * 仅仅是为了确保合并结果可以顺利存放到 nums1 中。
 *
 *
 *
 *
 * 提示：
 *
 *
 * nums1.length == m + n
 * nums2.length == n
 * 0 <= m, n <= 200
 * 1 <= m + n <= 200
 * -10^9 <= nums1[i], nums2[j] <= 10^9
 *
 *
 *
 *
 * 进阶：你可以设计实现一个时间复杂度为 O(m + n) 的算法解决此问题吗？
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

// @lc code=start
class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) {
            nums1 = nums2;
        }
        int j = m + n - 1;
        int i = m - 1;
        int k = n - 1;
        while (!nums2.empty() && i >= 0) {
            if (nums1[i] > nums2[k]) {
                swap(nums1[i], nums1[j]);
                i--;
            } else {
                swap(nums2[k], nums1[j]);
                k--;
                nums2.pop_back();
            }
            j--;
        }
        if (!nums2.empty() && i < 0) {
            while (!nums2.empty()) {
                nums1[j--] = nums2[k--];
                nums2.pop_back();
            }
        }
    }
};
// @lc code=end
int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> nums1 = {4, 0, 0, 0, 0, 0};
    vector<int> nums2 = {1, 2, 3, 5, 6};
    int m = 1, n = 5;
    s.merge(nums1, m, nums2, n);
    for (auto&& num : nums1) {
        cout << num << ",";
    }

    return 0;
}
