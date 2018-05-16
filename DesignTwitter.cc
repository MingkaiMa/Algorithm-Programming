class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        post[userId].push_back(make_pair(timestamp, tweetId));
        ++timestamp;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> lst;
        lst.push_back(userId);
        
        vector<int> fo = followers[userId];
        
        for(auto& i: fo)
            lst.push_back(i);
        
        vector<pair<int, int>> toPrint;
        
        for(auto& u: lst)
        {
            for(auto& t: post[u])
            {
                if(find(toPrint.begin(), toPrint.end(), t) == toPrint.end())
                    toPrint.push_back(t);
            }
        }
        
        auto cmp = [](pair<int, int> a, pair<int, int> b)   
        { return a.first > b.first;};
        
        sort(toPrint.begin(), toPrint.end(), cmp);
        
        vector<int> res;
        
        int k = 10;
        
        for(auto& i: toPrint)
        {
            if(k > 0)
                res.push_back(i.second);
            k--;
        }
        
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        vector<int> curr = followers[followerId];
        
        if(curr.size() == 0)
            followers[followerId].push_back(followeeId);
        else if(find(curr.begin(), curr.end(), followeeId) == curr.end())
            followers[followerId].push_back(followeeId);
        

        
            
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        vector<int> curr = followers[followerId];
        

        auto it = find(curr.begin(), curr.end(), followeeId);
        if(it != curr.end())
            curr.erase(it);
        
        followers[followerId] = curr;
        
        
            
    }
private:
    unordered_map<int, vector<int>> followers;
    map<int, vector<pair<int, int>>> post;
    int timestamp = 0;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
