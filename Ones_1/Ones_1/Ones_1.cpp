#include <iostream>
#include <vector>

const int lim = 1000000007;

long long fact(long long finish, long long start) {
    
    long long res = 1;
    for (int i = start; i <= finish; i++) {
        res *= i;
        res %= lim;
    }
    return res;
}

long long powModuled(long long num, long long step) {
    if (step == 1) {
        return num;
    }

    if (step%2 == 0) {
        long long t = powModuled(num, step / 2);
        return t * t % lim;
    }
    else {
        return powModuled(num, step - 1) * num % lim;
    }
}

long long backElement(long long x) {
    return powModuled(x, lim - 2);
}



int main()
{
    /*int n, k;
    std::cin >> n >> k;
    int lim = 1000000007;
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(k+1, 0));
    dp[0][0] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= k; j++) {
            dp[1][0] = 1;
            dp[1][1] = 1;
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            dp[i][j] = dp[i][j] % lim;
        }
    }
    std::cout << dp[n][k];*/

    /*int n, k;
    std::cin >> n >> k;
    int lim = 1000000007;
    std::vector<int> dp(k + 1, 0);
    std::vector<int>secdp(k + 1, 0);
    dp[0] = 1;
    secdp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[j] = secdp[j] + secdp[j - 1];
            dp[j] = dp[j] % lim;
        }
        secdp = dp;
    }
    std::cout << secdp[k];*/

    /*int n, k;
    std::cin >> n >> k;
    int lim = 1000000007;
    std::vector<int> dp(n + 1, 0);
    //std::vector<int>secdp(k + 1, 0);
    dp[0] = 1;
    //secdp[0] = 1;
    int temp = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {

            //dp[j] = secdp[j] + secdp[j - 1];
            dp[i] = dp[i - 1] + temp;
            dp[j] = dp[j] % lim;
        }
        //std::swap(dp, secdp);
    }
    std::cout << dp[n];*/

    int n, k;
    std::cin >> n >> k;
    long long res = 0;
    if (n > 2 * k) {
        res = fact(n, n - k + 1) * backElement(fact(k, 1)) % lim;
    }
    else {
        res = fact(n, k + 1) * backElement(fact(n - k, 1)) % lim;
    }
    std::cout << res;
}
