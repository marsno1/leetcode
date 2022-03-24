#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->n = times.size();
        this->times = times;
        this->tops.resize(n);
        unordered_map<int, int> votes; // person与票数的映射
        int top = 0; // 指向票数最多的那个人
        for (int i = 0; i < n; ++i) {
            int p = persons[i];
            ++votes[p];
            if (votes[p] >= votes[top]) {
                top = p;
            }
            // tops[i]表示在times[i]时刻票数最多的person
            tops[i] = top;
        }
    }
    
    int q(int t) {
        // 在times里查找小于等于t的最大的时刻值，用它的下标定位到tops中的person
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (times[mid] <= t) {
                // 排除左边，因为左边的值更小
                left = mid;
            } else {
                // 排除右边，因为右边不满足查找条件
                right = mid - 1;
            }
        }
        return tops[right];
    }

private:
    int n;
    vector<int> times;
    vector<int> tops; // 下标是时间，值是person
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
//leetcode submit region end(Prohibit modification and deletion)
