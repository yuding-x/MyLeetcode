// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem453.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 * A MATH QUESTION
 * important: find the min element in vector, we can use *min_element function.
 * vector.begin(),vector.end()
 * and how to loop through vector:
 * for(vector<int>::const_iterator iter = vector.begin(); iter != vector.end(); iter++){
 * cout<<(*iter)<<endl
 * }
 */

// @lc code=start
class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int minNum = *min_element(nums.begin(), nums.end());
        int res = 0;
        for (int num : nums)
        {
            res += num - minNum;
        }
        return res;
    }
};
// @lc code=end
