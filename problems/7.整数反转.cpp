/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include "common.h"

// @lc code=start
class Solution {
 public:
  // int reverse(int x) {
  //   int r = 0;
  //   int m;
  //   while (x != 0) {
  //     m = x % 10;
  //     // 检查溢出
  //     // Actually, it should be r>(INT_MAX-n)/10, but n/10 is 0, so omit it.
  //     if (r > INT_MAX / 10 || r < INT_MIN / 10) {
  //       return 0;
  //     }
  //     r = r * 10 + m;
  //     x /= 10;
  //     // std::cout << "m:" << m << ", r:" << r << ", x:" << x << std::endl;
  //   }

  //   return r;
  // }

  int reverse(int x) {
    long result = 0;
    while (x != 0) {
      result = result * 10 + x % 10;
      x /= 10;
    }
    return (result > INT_MAX || result < INT_MIN) ? 0 : result;
  }
};
// @lc code=end

int main() {
  Solution s;
  std::cout << (INT_MAX % 10) << std::endl;
  std::cout << s.reverse(1234) << std::endl;
  std::cout << s.reverse(INT_MAX) << std::endl;
  std::cout << s.reverse(INT_MIN) << std::endl;
  return 0;
}