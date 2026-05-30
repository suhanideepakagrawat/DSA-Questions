class Solution {
public:
    bool checkIfPangram(string sentence) {
        int count[26] = {0};
        int uniqueLetters = 0;
        
        for (int i = 0; i < sentence.length(); i++) {
            int index = sentence[i] - 'a';
            if (count[index] == 0) {
                uniqueLetters++;
            }
            count[index]++;
            if (uniqueLetters == 26) {
                return true;
            }
        }
        return false;
    }
};