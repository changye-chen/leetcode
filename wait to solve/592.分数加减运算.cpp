/*
 * @Author: czh 18782812147@163.com
 * @Date: 2022-07-27 21:15:19
 * @LastEditors: czh 18782812147@163.com
 * @LastEditTime: 2022-07-27 23:28:01
 * @FilePath: /.leetcode/592.分数加减运算.cpp
 * @Description:
 *
 * Copyright (c) 2022 by czh 18782812147@163.com, All Rights Reserved.
 */
/*
 * @lc app=leetcode.cn id=592 lang=cpp
 *
 * [592] 分数加减运算
 *
 * https://leetcode.cn/problems/fraction-addition-and-subtraction/description/
 *
 * algorithms
 * Medium (52.82%)
 * Likes:    110
 * Dislikes: 0
 * Total Accepted:    19.2K
 * Total Submissions: 32.4K
 * Testcase Example:  '"-1/2+1/2"'
 *
 * 给定一个表示分数加减运算的字符串 expression ，你需要返回一个字符串形式的计算结果。 
 *
 * 这个结果应该是不可约分的分数，即最简分数。 如果最终结果是一个整数，例如 2，你需要将它转换成分数形式，其分母为 1。所以在上述例子中,
 * 2 应该被转换为 2/1。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: expression = "-1/2+1/2"
 * 输出: "0/1"
 *
 *
 * 示例 2:
 *
 *
 * 输入: expression = "-1/2+1/2+1/3"
 * 输出: "1/3"
 *
 *
 * 示例 3:
 *
 *
 * 输入: expression = "1/3-1/2"
 * 输出: "-1/6"
 *
 *
 *
 *
 * 提示:
 *
 *
 * 输入和输出字符串只包含 '0' 到 '9' 的数字，以及 '/', '+' 和 '-'。 
 * 输入和输出分数格式均为 ±分子/分母。如果输入的第一个分数或者输出的分数是正数，则 '+' 会被省略掉。
 * 输入只包含合法的最简分数，每个分数的分子与分母的范围是  [1,10]。 如果分母是1，意味着这个分数实际上是一个整数。
 * 输入的分数个数范围是 [1,10]。
 * 最终结果的分子与分母保证是 32 位整数范围内的有效整数。
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
    class Fraction {
       public:
        int denominator;
        int numerator;
        Fraction() : denominator(3628800), numerator(0){};
        Fraction(string exp, char symbol) {
            numerator = exp[0] - '0';
            denominator = exp[2] - '0';
            if (symbol == '-') {
                numerator *= -1;
            }
        }
        void simplify() {
            if (numerator == 0) {
                denominator = 1;
                return;
            }
            int prime[4] = {2, 3, 5, 7};
            for (int i = 0; i < 4;) {
                if (numerator % prime[i] == 0 && denominator % prime[i] == 0) {
                    numerator /= prime[i];
                    denominator /= prime[i];
                } else
                    i++;
            }
        }
        void add(const Fraction& f) {
            numerator += (f.numerator * (denominator / f.denominator));
        }
        string toString() {
            simplify();
            return to_string(numerator) + "/" + to_string(denominator);
        }
    };
    string fractionAddition(string expression) {
        int len = expression.length();
        Fraction res;
        char symbol = '+';
        if (expression[0] != '-')
            expression = '+' + expression;
        for (int i = 3; i < len; i += 4) {
            Fraction f(expression.substr(i - 2, 3), expression[i - 3]);
            res.add(f);
        }
        return res.toString();
    }
};
// @lc code=end

int main(int argc, char const* argv[]) {
    string exp = "-5/2+10/3+7/9";
    string ans = "3/2";
    Solution s;
    if (ans == s.fractionAddition(exp)) {
        cout << "correct" << endl;
    }
    return 0;
}
