/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
#include "common.h"

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    auto *head = new ListNode(0);
    auto *curr = head;
    while (l1 || l2) {
      int val1 = l1 ? l1->val : 0;
      int val2 = l2 ? l2->val : 0;
      int sum = val1 + val2 + carry;
      carry = sum / 10;
      curr->next = new ListNode(sum % 10);
      curr = curr->next;
      if (l1) {
        l1 = l1->next;
      }
      if (l2) {
        l2 = l2->next;
      }
    }
    if (carry) {
      curr->next = new ListNode(carry);
    }
    return head->next;
  }
};
// @lc code=end
