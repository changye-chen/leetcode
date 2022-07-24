/*
 * @Author: czh 18782812147@163.com
 * @Date: 2022-07-24 20:22:29
 * @LastEditors: czh 18782812147@163.com
 * @LastEditTime: 2022-07-24 20:50:41
 * @FilePath: /.leetcode/leetcode/easy/53.最大子数组和.cpp
 * @Description:
 *
 * Copyright (c) 2022 by czh 18782812147@163.com, All Rights Reserved.
 */
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 *
 * https://leetcode.cn/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (54.76%)
 * Likes:    5140
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给你一个整数数组 nums
 * ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 *
 * 子数组 是数组中的一个连续部分。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出：6
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1]
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [5,4,-1,7,8]
 * 输出：23
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 *
 * 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
 *
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#define PI acos(1.0)
#define INT_MIN INT32_MIN;
using namespace std;

// @lc code=start
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        /**
            dp[i]表示到nums[i]时的最大子数组和
        */
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);
        }
        int res = INT_MIN;
        for (auto&& i : dp) {
            res = max(res, i);
        }
        return res;
    }
};
// @lc code=end

int main(int argc, char const* argv[]) {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution* solution = new Solution();
    int ans = solution->maxSubArray(nums);
    cout << ans << endl;
    delete solution;
    return 0;
}
