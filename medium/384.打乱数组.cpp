/*
 * @Author: czh 18782812147@163.com
 * @Date: 2022-07-26 21:16:11
 * @LastEditors: czh 18782812147@163.com
 * @LastEditTime: 2022-07-26 22:02:24
 * @FilePath: /.leetcode/leetcode/medium/384.打乱数组.cpp
 * @Description:
 *
 * Copyright (c) 2022 by czh 18782812147@163.com, All Rights Reserved.
 */
/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 *
 * https://leetcode.cn/problems/shuffle-an-array/description/
 *
 * algorithms
 * Medium (61.20%)
 * Likes:    290
 * Dislikes: 0
 * Total Accepted:    105.5K
 * Total Submissions: 172.3K
 * Testcase Example:
 * '["Solution","shuffle","reset","shuffle"]\n[[[1,2,3]],[],[],[]]'
 *
 * 给你一个整数数组 nums
 * ，设计算法来打乱一个没有重复元素的数组。打乱后，数组的所有排列应该是 等可能 的。
 *
 * 实现 Solution class:
 *
 *
 * Solution(int[] nums) 使用整数数组 nums 初始化对象
 * int[] reset() 重设数组到它的初始状态并返回
 * int[] shuffle() 返回数组随机打乱后的结果
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入
 * ["Solution", "shuffle", "reset", "shuffle"]
 * [[[1, 2, 3]], [], [], []]
 * 输出
 * [null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]
 *
 * 解释
 * Solution solution = new Solution([1, 2, 3]);
 * solution.shuffle();    // 打乱数组 [1,2,3] 并返回结果。任何
 * [1,2,3]的排列返回的概率应该相同。例如，返回 [3, 1, 2] solution.reset(); //
 * 重设数组到它的初始状态 [1, 2, 3] 。返回 [1, 2, 3] solution.shuffle();    //
 * 随机返回数组 [1, 2, 3] 打乱后的结果。例如，返回 [1, 3, 2]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 50
 * -10^6 <= nums[i] <= 10^6
 * nums 中的所有元素都是 唯一的
 * 最多可以调用 10^4 次 reset 和 shuffle
 *
 *
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#define INT_MIN INT32_MIN
#define INT_MAX INT32_MAX
using namespace std;

// @lc code=start
class Solution {
   public:
    vector<int> nums;
    Solution(vector<int>& nums) { this->nums = nums; }

    vector<int> reset() { return this->nums; }

    vector<int> shuffle() {
        vector<int> temp = nums;
        int len = temp.size();
        for (int i = 0; i < len; i++) {
            int n = rand() % (len - i) + i;
            swap(temp[i], temp[n]);
        }
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
int main(int argc, char const* argv[]) {
    vector<int> nums = {1, 2, 3, 5, 6, 7, 8, 9};
    Solution* soloution = new Solution(nums);
    int t = 10;
    while (t--) {
        vector<int> res = soloution->shuffle();
        for (auto&& num : res) {
            cout << num << ",";
        }
        cout << endl;
    }
    return 0;
}
