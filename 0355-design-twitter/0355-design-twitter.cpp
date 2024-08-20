class Compare {
    public:
    bool operator()(pair<int,int> obj1,pair<int,int>obj2){
        return obj1.first < obj2.first;
    }
};
class Twitter {
    map<int,unordered_set<int>> usersFollowList;
    map<int,vector<pair<int,int>> > usersTweetsList;
    int count;
public:
    Twitter() {
        count=0;
    }
    
    void postTweet(int userId, int tweetId) {
        usersTweetsList[userId].push_back({count,tweetId});
        count++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> newsFeed;
        vector<int>res;
        for(auto followee:usersFollowList[userId]){
            cout<<followee<<endl;
            for(auto tweet:usersTweetsList[followee]){
                newsFeed.push(tweet);
            }
        }
        for(auto tweet:usersTweetsList[userId]){
                newsFeed.push(tweet);
        }

        while(res.size()<10 && !newsFeed.empty()){
            res.push_back(newsFeed.top().second);
            newsFeed.pop();
        }
    return res;
    }
    
    void follow(int followerId, int followeeId) {
        usersFollowList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto pos = usersFollowList[followerId].find(followeeId);
        if(pos != usersFollowList[followerId].end())
            usersFollowList[followerId].erase(pos);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */