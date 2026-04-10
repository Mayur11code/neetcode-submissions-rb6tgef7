class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> m;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (m.find(key) == m.end()) return "";

        auto &v = m[key];
        int left = 0, right = v.size() - 1;
        int ans = -1;   // local candidate index

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (v[mid].first <= timestamp) {
                ans = mid;           // valid candidate
                left = mid + 1;      // try to find larger valid timestamp
            } else {
                right = mid - 1;
            }
        }

        if (ans != -1) return v[ans].second;
        return "";
    }
};
