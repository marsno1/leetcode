/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = letters.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (letters[mid] > target && (mid == 0 || letters[mid - 1] <= target)) {
                return letters[mid];
            }

            if (target < letters[mid]) {
                high = mid - 1;
            } else { // target >= letters[mid]
                low = mid + 1;
            }
        }

        return letters[0];
    }
};
// @lc code=end

