class Solution {
public:
    int countPrimes(int n)
    {
        if (n <= 1)
            return 0;

        bool prime[n + 1];

        for (int i = 2; i < n; i++)
            prime[i] = 1;

        int cnt = 0;
        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }

        for (int i = 2; i < n; i++)
            if (prime[i])
                cnt++;

        return cnt;
    }
};