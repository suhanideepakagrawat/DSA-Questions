class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,int> hash;
        for (int i = 0; i<sentence.length(); i++){
            char c = sentence[i];
            hash[c]++;
        }
        if (hash.size() == 26){return true;}
        return false;  
    }
};