/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while (l < r) {
            int mid = l + (r - l) / 2;
            bool finish = eatUp(piles, H, mid);
            if (finish) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    bool eatUp(vector<int>& piles, int H, int K) {
        int eatTime = 0;
        for (int i = 0; i < piles.size(); ++i) {
            eatTime += (piles[i] - 1) / K + 1;
        }
        return eatTime <= H;
    }
};
// @lc code=end

