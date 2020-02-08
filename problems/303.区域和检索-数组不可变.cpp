/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
    vector<int> sum;
public:
    NumArray(vector<int>& nums) {
        sum.assign(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            sum[i] = sum[i - 1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0) 
            return sum[j];
        else
            return sum[j] - sum[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

