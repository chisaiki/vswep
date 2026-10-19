// My original 

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // need a freq map first 
        std::unordered_map<int, int> freq = {};

        for(const int& val : nums){
            freq[val]++;
        }

        // max heap, store as value, key from prev map maybe
        std::priority_queue<std::pair<int, int>> max_heap;

        for(const auto& [key, val] : freq){
            max_heap.push({val, key});
        }


        // figure out the top k freq from the map
        std::vector<int> result = {};
        
        for(int i = 0; i < k; i++){
           result.push_back(max_heap.top().second);
           max_heap.pop();
        }
        
        return result; 
        
    }

    // AI Optimized Solution

    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;

    for (int num : nums) {
        freq[num]++;
    }

    vector<vector<int>> buckets(nums.size() + 1);

    for (const auto& [num, count] : freq) {
        buckets[count].push_back(num);
    }

    vector<int> result;
    result.reserve(k);

    for (int i = buckets.size() - 1; i >= 1; i--) {
        for (int num : buckets[i]) {
            result.push_back(num);

            if (result.size() == k) {
                return result;
            }
        }
    }

    return result;
}