/*
 * @Author: czh 18782812147@163.com
 * @Date: 2022-07-24 12:19:30
 * @LastEditors: czh 18782812147@163.com
 * @LastEditTime: 2022-07-24 12:29:40
 * @FilePath: /.leetcode/70.爬楼梯.cpp
 * @Description:
 *
 * Copyright (c) 2022 by czh 18782812147@163.com, All Rights Reserved.
 */
/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 *
 * https://leetcode.cn/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (53.86%)
 * Likes:    2541
 * Dislikes: 0
 * Total Accepted:    896.1K
 * Total Submissions: 1.7M
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 *
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 2
 * 输出：2
 * 解释：有两种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶
 * 2. 2 阶
 *
 * 示例 2：
 *
 *
 * 输入：n = 3
 * 输出：3
 * 解释：有三种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶 + 1 阶
 * 2. 1 阶 + 2 阶
 * 3. 2 阶 + 1 阶
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 45
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int Stairs[46] = {0};
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (!Stairs[n])
            Stairs[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return Stairs[n];
    }
};
// @lc code=end
