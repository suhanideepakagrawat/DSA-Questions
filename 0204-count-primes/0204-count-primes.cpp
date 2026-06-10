class Solution {
public:
    int countPrimes(int n) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if (n <= 2) return 0;
        std::vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        int limit = std::sqrt(n);
        for (int i = 2; i <= limit; ++i) {
            if (isPrime[i]) {
                for (long long j = (long long)i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        int primeCount = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                primeCount++;
            }
        }
        return primeCount;
    }
};