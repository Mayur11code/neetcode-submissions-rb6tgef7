class TweetNode {

    public:
    pair<int, int> p;
    TweetNode *next;

    inline static int time=0;
    
    // Constructors
    TweetNode() : next(nullptr) {
        p.first = -1;
        p.second = time;
    }
    TweetNode(int x) : next(nullptr) {
        p.first = x;
        p.second = time;
        time++;
    }
    TweetNode(int x, TweetNode* next) :  next(next) {
        p.first = x;
        p.second = time;
        time++;
    }
};

class Twitter {

    struct Compare {
        bool operator()(TweetNode* a, TweetNode* b) {
            return a->p.second < b->p.second;
        }
    };
    public:
    unordered_map<int, unordered_set<int>> m;
    unordered_map<int, TweetNode*> userTweets;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        TweetNode* head = new TweetNode(tweetId);
        if(userTweets[userId]){
            head->next = userTweets[userId];
        }
            userTweets[userId]= head;
    }
    
vector<int> getNewsFeed(int userId) {
        priority_queue<TweetNode*, vector<TweetNode*>, Compare> pq;
        vector<int> newsfeed;

        // 1. Gather all target users (Self + Followees)
        vector<int> targets;
        targets.push_back(userId); 
        if (m.count(userId)) {
            for (int followeeId : m[userId]) {
                if(followeeId == userId){
                    continue;
                }
                targets.push_back(followeeId);
            }
        }

        // 2. The For Loop: Seed the heap with the initial head nodes
        for (int target : targets) {
            if (userTweets.count(target) && userTweets[target] != nullptr) {
                pq.push(userTweets[target]);
            }
        }

        // 3. The While Loop: K-Way extraction of the 10 newest tweets
        while (!pq.empty() && newsfeed.size() < 10) {
            TweetNode* topNode = pq.top();
            pq.pop();

            newsfeed.push_back(topNode->p.first); // Record the tweetId

            // If this user has an older tweet, push it into the heap to compete
            if (topNode->next != nullptr) {
                pq.push(topNode->next);
            }
        }

        return newsfeed;
    }
    
    void follow(int followerId, int followeeId) {
        m[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
                m[followerId].erase(followeeId);

    }
};
