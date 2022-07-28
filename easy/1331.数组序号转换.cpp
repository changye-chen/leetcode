/*
 * @Author: czh 18782812147@163.com
 * @Date: 2022-07-28 21:36:46
 * @LastEditors: czh 18782812147@163.com
 * @LastEditTime: 2022-07-28 22:10:55
 * @FilePath: /.leetcode/1331.数组序号转换.cpp
 * @Description:
 *
 * Copyright (c) 2022 by czh 18782812147@163.com, All Rights Reserved.
 */
/*
 * @lc app=leetcode.cn id=1331 lang=cpp
 *
 * [1331] 数组序号转换
 *
 * https://leetcode.cn/problems/rank-transform-of-an-array/description/
 *
 * algorithms
 * Easy (52.99%)
 * Likes:    108
 * Dislikes: 0
 * Total Accepted:    36.6K
 * Total Submissions: 60.9K
 * Testcase Example:  '[40,10,20,30]'
 *
 * 给你一个整数数组 arr ，请你将数组中的每个元素替换为它们排序后的序号。
 *
 * 序号代表了一个元素有多大。序号编号的规则如下：
 *
 *
 * 序号从 1 开始编号。
 * 一个元素越大，那么序号越大。如果两个元素相等，那么它们的序号相同。
 * 每个数字的序号都应该尽可能地小。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：arr = [40,10,20,30]
 * 输出：[4,1,2,3]
 * 解释：40 是最大的元素。 10 是最小的元素。 20 是第二小的数字。 30
 * 是第三小的数字。
 *
 * 示例 2：
 *
 * 输入：arr = [100,100,100]
 * 输出：[1,1,1]
 * 解释：所有元素有相同的序号。
 *
 *
 * 示例 3：
 *
 * 输入：arr = [37,12,28,9,100,56,80,5,12]
 * 输出：[5,3,4,2,8,6,7,1,3]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= arr.length <= 10^5
 * -10^9 <= arr[i] <= 10^9
 *
 *
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#define INT_MIN INT32_MIN
#define INT_MAX INT32_MAX
using namespace std;

// @lc code=start
class Solution {
   public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, vector<int>> map;
        vector<int> ans(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            vector<int> tmp;
            if (map.find(arr[i]) != map.end()) {
                map[arr[i]].push_back(i);
            } else {
                tmp.push_back(i);
                map.emplace(arr[i], tmp);
            }
        }
        sort(arr.begin(), arr.end());
        for (int i = 0, j = 0; i < arr.size(); i++) {
            vector<int> tmp = map[arr[i]];
            j++;
            if (tmp.size() == 1) {
                ans[tmp[0]] = j;
            } else {
                for (auto&& index : tmp) {
                    ans[index] = j;
                }
                i += tmp.size() - 1;
            }
        }
        return ans;
    }
};
// @lc code=end
int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> arr = {100, 100, 100};
    vector<int> ans = s.arrayRankTransform(arr);
    for (auto&& i : ans) {
        cout << i << ",";
    }
    return 0;
}
