/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
#include "common.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int romanToInt(string s) {
    char c;
    char n;
    int sum = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      c = s[i];
      n = s[i + 1];
      switch (c) {
        case 'M':
          sum += 1000;
          break;
        case 'D':
          sum += 500;
          break;
        case 'C':
          if (n == 'M') {
            sum += 900;
            ++i;
          } else if (n == 'D') {
            sum += 400;
            ++i;
          } else {
            sum += 100;
          }
          break;
        case 'L':
          sum += 50;
          break;
        case 'X':
          if (n == 'C') {
            sum += 90;
            ++i;
          } else if (n == 'L') {
            sum += 40;
            ++i;
          } else {
            sum += 10;
          }
          break;
        case 'V':
          sum += 5;
          break;
        case 'I':
          if (n == 'X') {
            sum += 9;
            ++i;
          } else if (n == 'V') {
            sum += 4;
            ++i;
          } else {
            sum += 1;
          }
          break;
        default:
          break;
      }
    }
    return sum;
  }
};
// @lc code=end

int main() {
  Solution s;
  string str = "MCDL";
  std::cout << s.romanToInt(str) << std::endl;
  return 0;
}