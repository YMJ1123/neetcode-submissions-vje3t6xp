class Twitter {
private:
    int time_counter; // 全域時間戳記
    // 記錄誰追蹤了誰： followerId -> set of followeeIds
    unordered_map<int, unordered_set<int>> follows;
    // 記錄每個人的推文： userId -> vector of {time, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;
public:
    Twitter() {
        time_counter = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        // tweets.insert({userId, {time_counter, tweetId}});
        tweets[userId].push_back({time_counter, tweetId});
        time_counter++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;
        for (pair<int, int> t : tweets[userId]){
            maxHeap.push(t);
        }
        for (int i : follows[userId]){
            for (pair<int, int> t : tweets[i]){
                maxHeap.push(t);
            }
        }

        vector<int> result;
        // for (int j=0; j<10; j++){
        while (!maxHeap.empty() && result.size() < 10) {
            
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        // 如果我追蹤我自己 不行
        if (followerId == followeeId){return;}
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
