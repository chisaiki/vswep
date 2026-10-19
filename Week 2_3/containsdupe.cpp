 bool containsDuplicate(vector<int>& nums) {

        std::set<int> seen = {};

        for (auto value : nums){
            if (seen.contains(value)){
                return true;
            }

            seen.insert(value);
        }

        return false;
        
    }