class Solution {
public:
    int firstUniqChar(string s) {
        int count[256] = {0};
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            count[c]++;
        } 
        for (int i = 0; i < s.length(); i++){
            char c = s[i];
            if (count[c] == 1){
                return i;
            }
        }
        return -1;
    }
};