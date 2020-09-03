/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include "common.h"

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 余数及对应的index
        map<int, int> mp;
        vector<int> solution(2, -1);
        for (size_t i = 0; i < nums.size(); ++i)
        {
            auto it = mp.find(target - nums[i]);
            if (it != mp.end())
            {
                solution[0] = it->second;
                solution[1] = static_cast<int>(i);
                break;
            }
            else
            {
                mp.emplace(nums[i], i);
            }
        }

        return solution;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> v{2, 7, 11, 15};
    cout << s.twoSum(v, 9) << endl;
    return 0;
}
