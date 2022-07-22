/*
 * @Author: czh 18782812147@163.com
 * @Date: 2022-07-22 15:30:04
 * @LastEditors: czh 18782812147@163.com
 * @LastEditTime: 2022-07-22 15:45:59
 * @FilePath: /.leetcode/206.反转链表.cpp
 * @Description:
 *
 * Copyright (c) 2022 by czh 18782812147@163.com, All Rights Reserved.
 */
/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode.cn/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (73.17%)
 * Likes:    2638
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [1,2]
 * 输出：[2,1]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目范围是 [0, 5000]
 * -5000
 *
 *
 *
 *
 * 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
 *
 *
 *
 */
// Definition for singly-linked list.
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#define PI acos(1.0)

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// Definition for singly-linked list.

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        ListNode* q = nullptr;
        ListNode* t = nullptr;
        while (p) {
            t = p;
            p = p->next;
            t->next = q;
            q = t;
        }
        return q;
    }
};
// @lc code=end
