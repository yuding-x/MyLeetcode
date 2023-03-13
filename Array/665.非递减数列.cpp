// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem665.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 * 贪心算法，瞻前顾后法：
 * 遇到nums[i]>nums[i+1]的情况，要么把当前元素缩小，要么把[i+1]放大，遍历一圈，保证每个有序就行
 * https://leetcode.cn/problems/non-decreasing-array/description/
 *
 * algorithms
 * Medium (27.65%)
 * Likes:    728
 * Dislikes: 0
 * Total Accepted:    96K
 * Total Submissions: 347.2K
 * Testcase Example:  '[4,2,3]'
 *
 * 给你一个长度为 n 的整数数组 nums ，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。
 *
 * 我们是这样定义一个非递减数列的： 对于数组中任意的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [4,2,3]
 * 输出: true
 * 解释: 你可以通过把第一个 4 变成 1 来使得它成为一个非递减数列。
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [4,2,1]
 * 输出: false
 * 解释: 你不能在只改变一个元素的情况下将其变为非递减数列。
 *
 *
 *
 *
 * 提示：
 *
 *
 *
 * n == nums.length
 * 1 <= n <= 10^4
 * -10^5 <= nums[i] <= 10^5
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        // n是大小，cnt计数
        int n = nums.size(), cnt = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            // x:当前数，y后一个数
            int x = nums[i], y = nums[i + 1];
            // 如果当前数大于后一个，即不满足后面的条件
            if (x > y)
            {
                // 计数++，因为如果只有一个不满足，还可以修改
                cnt++;
                // 如果超过一个，那就直接g
                if (cnt > 1)
                {
                    return false;
                }
                // 排除第一个元素没有前一项，剩下的，如果后一项小于前一项，把后一项扩大为最小的满足条件的值，即当前值
                if (i > 0 && y < nums[i - 1])
                {
                    nums[i + 1] = x;
                }
            }
        }
        return true;
    }
};
// @lc code=end
