class Solution {
public:
    string countAndSay(int n) {
        // Base case
        if (n == 1) return "1";
        
        string current = "1";
        
        // Generate the sequence iteratively up to n
        for (int i = 2; i <= n; ++i) {
            string next_str = "";
            int len = current.length();
            
            int j = 0;
            while (j < len) {
                char ch = current[j];
                int count = 0;
                
                // Count consecutive identical characters
                while (j < len && current[j] == ch) {
                    count++;
                    j++;
                }
                
                // Append the count and the character to the next string representation
                next_str += to_string(count) + ch;
            }
            
            // Move to the next sequence item
            current = next_str;
        }
        
        return current;
    }
};