class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 0;
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            int currentLen = right - left - 1;
            if (currentLen > maxLen) {
                maxLen = currentLen;
                start = left + 1;
            }
        };
        for (int i = 0; i < s.length(); i++) {
            expandAroundCenter(i, i);     
            expandAroundCenter(i, i + 1); 
        }
        return s.substr(start, maxLen);
    }
};