/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode.cn/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (44.62%)
 * Likes:    3419
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.6M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 *
 * 有效字符串需满足：
 *
 *
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "()"
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "()[]{}"
 * 输出：true
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "(]"
 * 输出：false
 *
 *
 * 示例 4：
 *
 *
 * 输入：s = "([)]"
 * 输出：false
 *
 *
 * 示例 5：
 *
 *
 * 输入：s = "{[]}"
 * 输出：true
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * s 仅由括号 '()[]{}' 组成
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
    bool isValid(string s) {
        stack<char> st;
        int len = s.length();
        st.push(s[0]);
        if (len % 2)
            return false;
        for (int i = 1; i < len; i++) {
            if (st.empty()) {
                st.push(s[i]);
                continue;
            }
            char ch = st.top();
            switch (s[i]) {
                case ')':
                    if (ch == '(')
                        st.pop();
                    else
                        return false;
                    break;
                case '}':
                    if (ch == '{')
                        st.pop();
                    else
                        return false;
                    break;
                case ']':
                    if (ch == '[')
                        st.pop();
                    else
                        return false;
                    break;
                default:
                    st.push(s[i]);
                    break;
            }
        }
        //有左括号未配对
        if (!st.empty()) {
            return false;
        }
        return true;
    }
};
// @lc code=end
int main(int argc, char const* argv[]) {
    string test = "()({{[]}})[[[[]])]{}";
    Solution s;
    cout << s.isValid(test) << endl;
    return 0;
}
