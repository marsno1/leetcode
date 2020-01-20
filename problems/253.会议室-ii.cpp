struct CompStart {
    bool operator() (vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
};

// This is a greater<T>
struct CompEnd {
    bool operator() (vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), CompStart());
        priority_queue<vector<int>, vector<vector<int>>, CompEnd> pq;
        for (int i = 0; i < intervals.size(); ++i) {
            if (pq.empty()) {
                pq.push(intervals[i]);
            } else {
                vector<int> x = pq.top();
                if (intervals[i][0] >= x[1]) {
                    pq.pop();
                    pq.push(intervals[i]);
                } else {
                    pq.push(intervals[i]);
                }
            }
        }
        return pq.size();
    }
};