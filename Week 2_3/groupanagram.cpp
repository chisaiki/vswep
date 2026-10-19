    // My Original
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<string>> anagrams; 
        std::vector<std::vector<std::string>> results; 

        for (auto words : strs){
            std::string temp = words;
            std::sort(temp.begin(), temp.end());

            anagrams[temp].push_back(words);
        }

        for (auto [key, value] : anagrams){
            results.push_back(value);
        }

        return results;
        
    }

/*AI Optimized Solution*/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagrams;

    for (const auto& word : strs) {
        int count[26] = {};

        for (char c : word) {
            count[c - 'a']++;
        }

        string key;
        key.reserve(26);

        for (int freq : count) {
            key.push_back(static_cast<char>(freq));
        }

        anagrams[key].push_back(word);
    }

    vector<vector<string>> results;
    results.reserve(anagrams.size());

    for (auto& [key, group] : anagrams) {
        results.push_back(std::move(group));
    }

    return results;
}