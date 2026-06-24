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
            //O(1) time and space
            cout << "Time: " << time << " for tweet: " << tweetId << endl;
            pair<int, int> newTweet = make_pair(time, tweetId);
            tweets[userId].push_back(newTweet);
            time++;
        }

        vector<int> getNewsFeed(int userId) {
            //overall, time O(nlogn) space O(n * m)
            //get users userid follows
            unordered_set<int> following = follows[userId]; 
            following.insert(userId); //consider self O(n) space number of used id followees

            priority_queue<pair<int, int>> latests; //minheap O(n) space tweets within it
            for(int followee : following) { //O(n) time
                const vector<pair<int, int>>& followeeTwts = tweets[followee];
                int totalTwts = followeeTwts.size();
                for(int i = totalTwts - 1; i >= (max(0, totalTwts - 10)); i--) { //O(1), u check max 10 twts
                    latests.push(followeeTwts[i]); //O(logn)
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
            //O(1) time and space
            //add followeeId to follow list of the follower
            follows[followerId].insert(followeeId);
        }

        void unfollow(int followerId, int followeeId) {
            //O(1) time and space
            follows[followerId].erase(followeeId);
        }
};