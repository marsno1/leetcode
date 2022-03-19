#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Twitter {
public:
    Twitter() {
        userIdToFolloweeIds.resize(501);
        userIdToTweetIds.resize(501);
        timeId = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        userIdToTweetIds[userId].push_back({timeId, tweetId});
        ++timeId;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> q;
        for (const auto & p : userIdToTweetIds[userId]) {
            q.push(p);
        }
        for (const int fid : userIdToFolloweeIds[userId]) {
            for (const auto & p : userIdToTweetIds[fid]) {
                q.push(p);
            }
        }
        int count = 0;
        vector<int> feeds;
        while (!q.empty() && count < 10) {
            feeds.push_back(q.top().second);
            q.pop();
            ++count;
        }
        return feeds;
    }
    
    void follow(int followerId, int followeeId) {
        userIdToFolloweeIds[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userIdToFolloweeIds[followerId].erase(followeeId);
    }

private:
    vector<vector<pair<int, int>>> userIdToTweetIds;
    vector<unordered_set<int>> userIdToFolloweeIds;
    int timeId;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
//leetcode submit region end(Prohibit modification and deletion)
