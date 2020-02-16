/*
 * @lc app=leetcode.cn id=855 lang=cpp
 *
 * [855] 考场就座
 */

// @lc code=start
class ExamRoom {
    set<int> s;
    int n;
public:
    ExamRoom(int N) {
        n = N;
    }
    
    int seat() {
        if (s.empty()) {
            s.insert(0);
            return 0;
        } 
        
        // 默认座位[0]可以就座，此时的距离即为座位[0]与下一个学生的距离
        // 如果座位[0]有学生也不要紧，此时最大距离的初始值为0，不影响后续计算
        int max_dist = *s.begin();
        int ans = 0;
        int dist;
        int prev = -1;
        for (auto i : s) {
            // 每次迭代取一个新的学生所在的位置
            if (prev != -1) {
                int mid = prev + (i - prev) / 2;
                int dist = mid - prev;
                if (dist > max_dist) {
                    max_dist = dist;
                    ans = mid;
                }
            }
            prev = i;
        }

        // 最后检查一下最后一个座位是不是空的
        // 如果是空的，再计算最后一段距离
        if (*s.rbegin() != n - 1) {
            dist = n - 1 - *s.rbegin();
            if (dist > max_dist) {
                max_dist = dist;
                ans = n - 1;
            }
        }

        s.insert(ans);
        return ans;
    }
    
    void leave(int p) {
        s.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
// @lc code=end

