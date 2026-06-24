class Twitter {
    public:
        unordered_map<int, unordered_set<int>> follows;
        unordered_map<int, vector<pair<int, int>>> tweets;
        int time;

        Twitter() {
            this->follows = {};
            this->tweets = {};
            this->time = 0;
        }

        void postTweet(int userId, int tweetId) {
            cout << "Time: " << time << " for tweet: " << tweetId << endl;
            pair<int, int> newTweet = make_pair(time, tweetId);
            tweets[userId].push_back(newTweet);
            time++;
        }

        vector<int> getNewsFeed(int userId) {
            //get users userid follows
            unordered_set<int> following = follows[userId];
            following.insert(userId); //consider self

            priority_queue<pair<int, int>> latests; //minheap
            for(int followee : following) {
                vector<pair<int, int>> followeeTwts = tweets[followee];
                reverse(followeeTwts.begin(), followeeTwts.end());
                
                int minTweets = min(10, (int)followeeTwts.size());
                for(int i = 0; i < minTweets; i++) {
                    latests.push(followeeTwts[i]);
                }
            }

            vector<int> feed;
            int count = 0;
            while(latests.size() > 0 && count < 10) {
                int feedTwt = latests.top().second;
                feed.push_back(feedTwt);
                latests.pop();
                count++;
            }

            return feed;

        }

        void follow(int followerId, int followeeId) {
            //add followeeId to follow list of the follower
            follows[followerId].insert(followeeId);
        }

        void unfollow(int followerId, int followeeId) {
            follows[followerId].erase(followeeId);
        }
};