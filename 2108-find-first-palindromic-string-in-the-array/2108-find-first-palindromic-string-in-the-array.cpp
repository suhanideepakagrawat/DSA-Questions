class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (int i = 0; i < words.size(); i++){
            int n = words[i].size();
            int l = 0;
            int r = n - 1;
            string s = words[i];
            while ( l < r){
                if (s[l] == s[r]){
                    l ++;
                    r --;
                }
                else {
                    break;
                }
            }
            if ( l>= r){
                return s;
            }
        }
    return "";
        
    }
};