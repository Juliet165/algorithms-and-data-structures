/*#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector <int> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::vector <std::vector<int>> dp(n, std::vector<int>(n));
    if (a[0] == b[0]) {
        dp[0][0] = 1;
        if (n > 1) {
            dp[1][0] = 1;
            dp[0][1] = 1;
        }
    }
    else {
        dp[0][0] = 0;
        if (n > 1) {
            if (a[1] == b[0]) {
                dp[1][0] = 1;
            }
            if (a[0] == b[1]) {
                dp[0][1] = 1;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    std::cout << dp[n - 1][n - 1];
    if (dp[n - 1][n - 1] == 0) {
        return 0;
    }
    std::cout << std::endl; 
    std::vector <int> first;
    std::vector <int> second;
    int i = n - 1;
    int j = n - 1;
    while (i > 0 && j > 0) {
        if (a[i] == b[j]) {
            first.push_back(i);
            second.push_back(j);
            i--;
            j--;
        }
        else {
            if (dp[i][j] == dp[i - 1][j]) {
                i--;
            }
            else if (dp[i][j] == dp[i][j - 1]) {
                j--;
            }
        }
    }
    if (n > 1) {
        if (a[1] == b[0]) {
            first.push_back(1);
            second.push_back(0);
        }
        if (a[0] == b[1]) {
            first.push_back(0);
            second.push_back(1);
        }
    }
    
    if (a[0] == b[0]) {
        first.push_back(0);
        second.push_back(0);

    }

    for (int i = first.size() - 1; i >= 0; i--) {
        std::cout << first[i] << " ";
    }
    std::cout << std::endl;
    for (int i = second.size() - 1; i >= 0; i--) {
        std::cout << second[i] << " ";
    }
}*/

#include <iostream>
#include <algorithm>
#include <vector>
/*
int main()
{
    int n;
    std::cin >> n;
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector <int> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::vector <std::vector<int>> dp(n, std::vector<int>(n));
    if (a[0] == b[0]) {
        dp[0][0] = 1;
        if (n > 1) {
            dp[1][0] = 1;
            dp[0][1] = 1;
        }
    }
    else {
        dp[0][0] = 0;
        if (n > 1) {
            if (a[1] == b[0]) {
                dp[1][0] = 1;
            }
            if (a[0] == b[1]) {
                dp[0][1] = 1;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    if (dp[n - 1][n - 1] == 0) {
        std::cout << 0;
    }
    else {
        std::cout << dp[n - 1][n - 1] << std::endl;
        std::vector <int> first;
        std::vector <int> second;
        int i = n - 1;
        int j = n - 1;
        while (i > 0 && j > 0) {
            if (a[i] == b[j]) {
                first.push_back(i);
                second.push_back(j);
                i--;
                j--;
            }
            else {
                if (dp[i][j] == dp[i - 1][j]) {
                    i--;
                }
                else if (dp[i][j] == dp[i][j - 1]) {
                    j--;
                }
            }
        }
        if (n > 1) {
            if (a[1] == b[0]) {
                first.push_back(1);
                second.push_back(0);
            }
            else if (a[0] == b[1]) {
                first.push_back(0);
                second.push_back(1);
            }
        }
        if (a[0] == b[0]) {
            first.push_back(0);
            second.push_back(0);

        }

        for (int i = first.size() - 1; i >= 0; i--) {
            std::cout << first[i] << " ";
        }
        std::cout << std::endl;
        for (int i = second.size() - 1; i >= 0; i--) {
            std::cout << second[i] << " ";
        }
    }
    
}*/

int main() {
    int n;
    std::cin >> n;
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector <int> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::vector <std::vector<int>> dp(n+1, std::vector<int>(n+1, 0));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }


   /*int max_len = dp[n][n];
    int i = n, j = n;
    std::vector<int> seq_A;
    std::vector<int> seq_B;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[i - 1]) {
            seq_A.push_back(i - 1);
            seq_B.push_back(j - 1);
            i--;
            j--;
        }
        else {
            if (dp[i][j] == dp[i - 1][j]) {
                i--;
            }
            else if (dp[i][j] == dp[i][j - 1]) {
                j--;
            }
        }
    }*/
    
    

    if (dp[n][n] == 0) {
        std::cout << 0;
    }
    else {
        std::cout << dp[n][n] << std::endl;
        std::vector <int> first;
        std::vector <int> second;
        int i = n;
        int j = n;
        while (i > 0 && j > 0) {
            if (a[i - 1] == b[j - 1]) {
                first.push_back(i - 1);
                second.push_back(j - 1);
                i--;
                j--;
            }
            else {
                if (dp[i][j] == dp[i - 1][j]) {
                    i--;
                }
                else if (dp[i][j] == dp[i][j - 1]) {
                    j--;
                }
            }
        }
        for (int i = first.size() - 1; i >= 0; i--) {
            std::cout << first[i] << " ";
        }
        std::cout << std::endl;
        for (int i = second.size() - 1; i >= 0; i--) {
            std::cout << second[i] << " ";
        }
    }

    //std::cout << max_len << std::endl;
    /*for (int i = dp[n][n] - 1; i >= 0; i--) {
        std::cout << seq_A[i] << " ";
    }
    std::cout << std::endl;
    for (int i = dp[n][n] - 1; i >= 0; i--) {
        std::cout << seq_B[i] << " ";
    }
    std::cout << std::endl;*/
    

}