#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    /*int n;
    std::cin >> n;
    std::vector <int> mosq(n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> mosq[i];
    }
    int sum = mosq[n-1];
    int num = 2;
    int pos = n - 1;
    std::vector <int> moves;
    moves.push_back(n);
    for (int i = n-1; i > 2; i--) {
        if (i == 1) {
            sum = -1;
        }
        num++;
        if (mosq[i - 2] > mosq[i - 3]) {
            sum += mosq[i - 2];
            moves.push_back(i-1);
            pos = i;
            i = i - 2;
        }
        else {
            sum += mosq[i - 3];
            moves.push_back(i-2);
            pos = i;
            i = i - 3;
        }
    }
    moves.push_back(1);
    moves.resize(num);
    sum += mosq[0];
    if (pos < 2) {
        sum = -1;
    }
    std::cout << sum;
    if (sum != -1) {
        std::cout<< std::endl;
        for (int i = num-1; i >= 0; i--) {
            std::cout << moves[i] << " ";
        }
    }*/

    /*int n;
    std::cin >> n;
    std::vector <int> mosq(n, 0);
    std::vector <int> prev(n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> mosq[i];
    }
    int res = 0;
    std::vector <int> dp(n+1);

    for (int i = 1; i <= n; i++) {
        if (i == 1 || i == 2) {
            dp[i] = mosq[i];
            prev[i] = 0;
        }
        else if (i >= 3) {
            dp[i] = mosq[i] + dp[i - 2];
            prev[i] = i - 2;
        }
        if (i >= 4 && dp[i - 3] + mosq[i] > dp[i]) {
            dp[i] = dp[i - 3] + mosq[i];
            prev[i] = i - 3;
        }
        if (i >= 5 && dp[i - 4] + mosq[i] > dp[i]) {
            dp[i] = dp[i - 4] + mosq[i];
            prev[i] = i - 4;
        }
    }

    //int ans = max(dp[n], max(dp[n - 1], dp[n - 2]));
    std::cout << res << std::endl;

    if (ans == dp[n]) {
        int i = n;
        while (i != 0) {
            cout << i << " ";
            i = prev[i];
        }
    }
    else if (ans == dp[n - 1]) {
        int i = n - 1;
        while (i != 0) {
            cout << i << " ";
            i = prev[i];
        }
    }
    else if (ans == dp[n - 2]) {
        int i = n - 2;
        while (i != 0) {
            cout << i << " ";
            i = prev[i];
        }
    }*/
    int n;
    std::cin >> n;
    std::vector <int> mosq(n);
    for (int i = 0; i < n; i++) {
        std::cin >> mosq[i];
    }
    std::vector <long long> dp(n, -1);
    dp[0] = mosq[0];
    /*if (n == 3) {
        dp[2] = mosq[0] + mosq[2];
    }
    for (int i = 3; i < n; i++) {
        dp[1] = -15;
        if (dp[i - 2] > dp[i - 3]) {
            dp[i] = dp[i - 2] + mosq[i];
        }
        else {
            dp[i] = dp[i - 3] + mosq[i];
        }
    }
    if (dp[n - 1] == -1) {
        std::cout << -1;
        return 0;
    }
    std::cout << dp[n - 1] << std::endl;
    std::vector <int> nums;
    nums.push_back(n);
    int i = n;
    while (i > 3) {
        if (dp[i - 3] <= dp[i - 4]) {
            nums.push_back(i - 3);
            i = i - 3;
        }
        else {
            nums.push_back(i - 2);
            i = i - 2;
        }
    }
    if (nums[nums.size() - 1] != 1) {
        nums.push_back(1);
    }
    for (int i = nums.size() - 1; i >= 0; i--) {
        std::cout << nums[i] << " ";
    }*/
    //std::cout << endl;
    if (n == 3) {
        dp[2] = mosq[0] + mosq[2];
    }
    for (int i = 3; i < n; i++) {
        dp[1] = -1;
        dp[2] = mosq[0] + mosq[2];
        if (dp[i - 2] > dp[i - 3]) {
            dp[i] = dp[i - 2] + mosq[i];
        }
        else {
            dp[i] = dp[i - 3] + mosq[i];
        }
    }
    if (dp[n - 1] == -1) {
        std::cout << -1;
    }
    else {
        std::cout << dp[n-1] << std::endl;
        std::vector <int> nums;
        nums.push_back(n);
        int i = n;
        while (i > 3){
            if (dp[i - 3] <= dp[i - 4]) {
                nums.push_back(i - 3);
                i = i - 3;
            }
            else {
                nums.push_back(i - 2);
                i = i - 2;
            }
        }
        if (nums[nums.size() - 1] != 1) {
            nums.push_back(1);
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            std::cout << nums[i] << " ";
        }
    }

}