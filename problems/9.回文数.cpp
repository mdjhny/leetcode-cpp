/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
#include "common.h"

// @lc code=start
class Solution {
 public:
  // bool isPalindrome(int x) { return x >= 0 && reverse(x) == x; }
  int reverse(int x) {
    int r = 0;
    int m;
    while (x != 0) {
      m = x % 10;
      // Checking the over/underflow.
      // Actually, it should be r>(INT_MAX-n)/10, but n/10 is 0, so omit it.
      if (r > INT_MAX / 10 || r < INT_MIN / 10) {
        return 0;
      }
      r = r * 10 + m;
      x /= 10;
    }

    return r;
  }

  bool isPalindrome(int x) {
    if (x < 0 || (x != 0 && x % 10 == 0)) return false;
    int sum = 0;
    while (x > sum) {
      sum = sum * 10 + x % 10;
      x = x / 10;
    }
    return (x == sum) || (x == sum / 10);
  }
};
// @lc code=end

int main() {
  Solution s;
  std::cout << std::boolalpha << s.isPalindrome(121) << std::endl;
  return 0;
}
