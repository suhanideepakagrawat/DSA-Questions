class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int m = num1.size();
        int n = num2.size();
        std::vector<int> result(m + n, 0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10; 
                result[i + j] += sum / 10;     
            }
        }
    
        std::string resultStr = "";
        for (int digit : result) {

            if (!(resultStr.empty() && digit == 0)) {
                resultStr.push_back(digit + '0');
            }
        }
        
        return resultStr.empty() ? "0" : resultStr;
    }
};