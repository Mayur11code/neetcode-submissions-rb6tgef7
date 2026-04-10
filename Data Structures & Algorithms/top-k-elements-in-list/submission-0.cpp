#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        // 1. Map to store frequency of each number
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        
        // 2. Bucket: index is frequency, value is a list of numbers with that frequency
        // We use n + 1 because a number could appear up to n times
        vector<vector<int>> buckets(n + 1);
        for (auto const& [num, freq] : counts) {
            buckets[freq].push_back(num);
        }
        
        // 3. Iterate backwards from the highest frequency bucket
        vector<int> result;
        for (int i = n; i >= 0; i--) {
            if (result.size() >= k) break;
            
            if (!buckets[i].empty()) {
                for (int num : buckets[i]) {
                    result.push_back(num);
                    if (result.size() == k) return result;
                }
            }
        }
        
        return result;
    }
};