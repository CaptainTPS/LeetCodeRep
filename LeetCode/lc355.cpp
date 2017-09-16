struct oneT{
        int userId;
        int tweetId;
        int stamp;
        oneT* next;

        oneT(int u, int t, int s):userId(u), tweetId(t), stamp(s), next(NULL){};
};


class cmpOneT{
public:
    bool operator()(oneT* a, oneT* b){
        return a->stamp < b->stamp;
    }
};

class Twitter {
public:


    /** Initialize your data structure here. */
    Twitter() {
        size = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        auto finder = data.find(userId);
        size++;
        if(finder == data.end()){
            data[userId] = new oneT(userId, tweetId, size);
        }else{
            auto ptr = finder->second;
            finder->second = new oneT(userId, tweetId, size);
            finder->second->next = ptr;
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<oneT*, vector<oneT*>, cmpOneT> pq;
        auto ptr = data[userId];
        if(ptr != NULL)
            pq.push(ptr);
        for(auto itr = relation[userId].begin(); itr != relation[userId].end(); itr++){
            int f = *itr;
            if(f == userId)
                continue;
            ptr = data[f];
            if(ptr != NULL)
                pq.push(ptr);
        }

        vector<int> feeds;
        while(feeds.size() < 10 && !pq.empty()){
            auto now = pq.top(); pq.pop();
            feeds.push_back(now->tweetId);
            now = now->next;
            if(now != NULL)
                pq.push(now);

        }
        return feeds;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        relation[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        relation[followerId].erase(followeeId);
    }

private:
    int size;
    

    unordered_map<int, oneT*> data;
    unordered_map<int, unordered_set<int>> relation;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */