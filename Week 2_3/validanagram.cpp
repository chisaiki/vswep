    bool isAnagram(string s, string t) {
        int alphabet[26] = {};

        for (auto letter : s){
            alphabet[letter - 'a']++;
        }

        for (auto letter : t){
            if(alphabet[letter - 'a'] > 0){
                alphabet[letter - 'a']--;
             }
             else{
                 return false;
             }
        }

        for (int value = 0; value < 26; value++){
            if (alphabet[value] != 0){
                return false; 
            }
        }

        return true;
        
    }