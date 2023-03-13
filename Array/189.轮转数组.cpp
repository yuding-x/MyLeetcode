// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem189.h"

using namespace std;
// @before-stub-for-debug-end
/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 *
 * https://leetcode.cn/problems/rotate-array/description/
 *
 * algorithms
 * Medium (44.20%)
 * Likes:    1756
 * Dislikes: 0
 * Total Accepted:    622.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,3,4,5,6,7]\n 3'
 *
 * 给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,2,3,4,5,6,7], k = 3
 * 输出: [5,6,7,1,2,3,4]
 * 解释:
 * 向右轮转 1 步: [7,1,2,3,4,5,6]
 * 向右轮转 2 步: [6,7,1,2,3,4,5]
 * 向右轮转 3 步: [5,6,7,1,2,3,4]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：nums = [-1,-100,3,99], k = 2
 * 输出：[3,99,-1,-100]
 * 解释: 
 * 向右轮转 1 步: [99,-1,-100,3]
 * 向右轮转 2 步: [3,99,-1,-100]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 * 0 <= k <= 10^5
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 尽可能想出更多的解决方案，至少有 三种 不同的方法可以解决这个问题。
 * 你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) k %= n;
        int leftRot = n - k;
        //输出数组的当前位置
        int pos = 0;
        vector<int> knums;
        //右转x = 左转n-x(leftRot)
        for(int i = 0; i < n; i++){
            //如果是前k个，就记录在别的数组里
            if(i < leftRot) {
                knums.push_back(nums[i]);
            }
            else{
                //如果是要提前的，就放到前面来
                nums[pos++] = nums[i];
            }
        }
        for(int j = 0; j < leftRot; j++){
            nums[pos++] = knums[j];
        }
    }
};
// @lc code=end

