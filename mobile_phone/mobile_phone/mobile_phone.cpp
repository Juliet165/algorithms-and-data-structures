#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

/*long long memo(std::vector <std::vector <long long>> dyn, std::vector <int> val, std::vector <std::vector <int>> cost, int i, int j) {
    if (dyn[i][j] != INT_MAX) {
        return dyn[i][j];
    }
    else {
        for (int im = 1; im <= i; im++) {
            for (int jm = 1; jm <= j; jm++) {
                /*if (dyn[im - 1][jm - 1] + val[im] >= dyn[im - 1][jm] + val[im] * (cost[im - 1][jm] + 1)) {
                    dyn[im][jm] = dyn[im - 1][jm] + val[im] * (cost[im - 1][jm] + 1);
                    cost[im][jm] = cost[im - 1][jm] + 1;
                }
                else {
                    dyn[im][jm] = dyn[im - 1][jm - 1] + val[im];
                    cost[im][jm] = 1;
                }
                if (memo(dyn, val, cost, im-1, jm-1) + val[im] >= memo(dyn, val, cost, im - 1, jm) + val[im] * (cost[im - 1][jm] + 1)) {
                    //dyn[im][jm] = dyn[im - 1][jm] +
                    dyn[im][jm] = memo(dyn, val, cost, im - 1, jm) + val[im] * (cost[im - 1][jm] + 1);
                    cost[im][jm] = cost[im - 1][jm] + 1;
                }
                else {
                    //dyn[im][jm] = dyn[im - 1][jm - 1] + val[im];
                    dyn[im][jm] = memo(dyn, val, cost, im - 1, jm - 1) + val[im];
                    cost[im][jm] = 1;
                }
            }
        }
    }
    long long answer = dyn[i][j];
    return answer;
}*/
/*
int main()
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("in.txt");
    fout.open("out.txt");
    int n, m;
    fin >> n >> m;
    std::vector <int> z(m + 1);
    for (int i = 1; i <= m; i++) {
        fin >> z[i];
    }
    
    std::vector <std::vector <long long>> dp(m + 1, std::vector <long long> (n + 1, INT_MAX));
    std::vector <std::vector <int>> c(m + 1, std::vector <int>(n + 1));
    dp[0][0] = 0;
    dp[1][0] = INT_MAX;
    dp[0][1] = 0;
    dp[1][1] = z[1];

    c[0][0] = 0;
    c[0][1] = 0;
    c[1][0] = INT_MAX;
    c[1][1] = 1;

    for (int i = 1; i <= std::min(m, n); i++) {
        dp[i][i] = dp[i - 1][i - 1] + z[i];
        c[i][i] = 1;
    }
    
    for (int i = 1; i <= m; i++) {
        dp[i][1] = dp[i - 1][1] + z[i] * i;
        c[i][1] = i;
    }

    
    for (int i = 1; i <= m; i++) {
        
        for (int j = 1; j <= std::min(i, n); j++) {
            if (dp[i - 1][j - 1] + z[i] >= dp[i - 1][j] + z[i] * (c[i - 1][j] + 1)) {
                dp[i][j] = dp[i - 1][j] + z[i] * (c[i - 1][j] + 1);
                c[i][j] = c[i - 1][j] + 1;
            }
            else {
                dp[i][j] = dp[i - 1][j - 1] + z[i];
                c[i][j] = 1;
            }
             
        }
    }
    
    //fout << dp[m - 1][n - 1];
    //long long ans = memo(dp, z, c, m, n);
    std::cout << dp[m][n];
    
    fin.close();
    fout.close();
}

/*if (dp[i - 1][j - 1] + z[i] < dp[i - 1][j] + z[i] * (c[i - 1][j] + 1)) {
                dp[i][j] = dp[i - 1][j - 1] + z[i];
                c[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i - 1][j] + z[i] * (c[i - 1][j] + 1);
                c[i][j] = c[i - 1][j] + 1;
            }*/

/*

int main()
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("in.txt");
    fout.open("out.txt");
    int n, m;
    fin >> n >> m;
    std::vector <int> z(m + 1);
    for (int i = 1; i <= m; i++) {
        fin >> z[i];
    }
    int s = 0;
    if (n >= m) {
        for (int i = 1; i <= m; i++) {
            s += z[i];
        }
        std::cout << s;
        return 0;
    }
    std::vector <std::vector <long long>> dp(m + 1, std::vector <long long>(n + 1));
    std::vector <std::vector <int>> c(m + 1, std::vector <int>(n + 1));
    dp[1][1] = z[1];
    c[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][i] = dp[i - 1][i - 1] + z[i];
        c[i][i] = 1;
    }
    for (int i = 2; i <= m; i++) {
        dp[i][1] = dp[i - 1][1] + z[i] * i;
        c[i][1] = i;
    }
    for (int i = 0; i <= m; i++) {
        dp[i][0] = INT_MAX;
    }
    for (int i = 0; i <= n; i++) {
        dp[0][i] = INT_MAX;
        if (i > 1) {
            dp[1][i] = INT_MAX;
        }
    }
    for (int i = 2; i <= m; i++) {
        for (int j = 2; j <= n; j++) {
            if (dp[i - 1][j - 1] + z[i] <= dp[i - 1][j] + z[i] * (c[i - 1][j] + 1)) {
                
                dp[i][j] = dp[i - 1][j - 1] + z[i];
                c[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i - 1][j] + z[i] * (c[i - 1][j] + 1);
                c[i][j] = c[i - 1][j] + 1;
            }

        }
    }

    std::cout << dp[m][n];
    fin.close();
    fout.close();
}*/
/*
int main()
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("in.txt");
    fout.open("out.txt");
    int n, m;
    fin >> n >> m;
    std::vector <int> z(m + 1);
    for (int i = 1; i <= m; i++) {
        fin >> z[i];
    }
    long long s = 0;
    if (n >= m) {
        for (int i = 1; i <= m; i++) {
            s += z[i];
        }
        fout << s;
        return 0;
    }
    std::vector <std::vector <long long>> dp(m + 1, std::vector <long long>(n + 1));
    std::vector <std::vector <int>> c(m + 1, std::vector <int>(n + 1));
    dp[1][1] = z[1];
    c[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][i] = dp[i - 1][i - 1] + z[i];
        c[i][i] = 1;
    }
    for (int i = 2; i <= m; i++) {
        dp[i][1] = dp[i - 1][1] + z[i] * i;
        c[i][1] = i;
    }
    for (int i = 0; i <= m; i++) {
        dp[i][0] = INT_MAX;
    }
    for (int i = 0; i <= n; i++) {
        dp[0][i] = INT_MAX;
        if (i > 1) {
            dp[1][i] = INT_MAX;
        }
    }
    for (int i = 2; i <= m; i++) {
        for (int j = 2; j <= n; j++) {
            if (j > i) {
                dp[i][j] = dp[i][i];
                break;
            }
            if (dp[i - 1][j - 1] + z[i] <= dp[i - 1][j] + z[i] * (c[i - 1][j] + 1)) {

                dp[i][j] = dp[i - 1][j - 1] + z[i];
                c[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i - 1][j] + z[i] * (c[i - 1][j] + 1);
                c[i][j] = c[i - 1][j] + 1;
            }

        }
    }

    fout << dp[m][n];
    fin.close();
    fout.close();
}*/

/*
int main() {
    std::ifstream fin;
    std::ofstream fout;
    fin.open("in.txt");
    fout.open("out.txt");
    int n, m;
    std::cin >> n >> m;
    std::vector <long long> z(m);
    for (int i = 0; i < m; i++) {
        std::cin >> z[i];
    }

    long long s = 0;
    if (n >= m) {
        for (int i = 0; i < m; i++) {
            s += z[i];
        }
        std::cout << s;
        return 0;
    }

    int k = m;
    std::vector <std::vector<std::vector<long long>>> 
        dp(m, std::vector<std::vector<long long>>(n, std::vector<long long>(k, LLONG_MAX)));

    //dp[0][0][0] = z[0];
    for (int i = 0; i < m; i++) {
        dp[0][0][i] = z[0];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int r = 0; r < m; r++) {
                if (i > 0) {
                    dp[i][0][r] = dp[i - 1][0][r] + z[i] * i;
                    if (r > 0 && j > 0) {
                        dp[i][j][0] = dp[i - 1][j - 1][r] + z[i];
                    }
                }
                dp[0][j][r] = z[0];                 
            }
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            for (int y = 1; y < m; y++) {
                dp[i][j][y] = dp[i - 1][j][y - 1] + z[i] * y;
            }
        }
    }

    s = dp[m - 1][n - 1][0];
    for (int i = 1; i < k; i++) {
        if (dp[m - 1][n - 1][i] < s) {
            s = dp[m - 1][n - 1][i];
        }
    }
    std::cout << s;
    fin.close();
    fout.close();
}
*/

int main()
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("in.txt");
    fout.open("out.txt");
    int n, m;
    fin >> n >> m;
    std::vector <unsigned long long> z(m + 1);
    for (int i = 1; i <= m; i++) {
        fin >> z[i];
    }
    long long s = 0;
    if (n >= m) {
        for (int i = 1; i <= m; i++) {
            s += z[i];
        }
        fout << s;
        return 0;
    }
    std::vector <std::vector <long long>> dp(m + 1, std::vector <long long>(n + 1, LLONG_MAX));
    std::vector <std::vector <long long>> c(m + 1, std::vector <long long>(m + 1, LLONG_MAX));
    
    for (int i = 1; i <= m; i++) {
        int k = 2;
        for (int j = i; j <= m; j++) {
            c[i][i] = z[i];
            if (j > i) {
                c[i][j] = c[i][j - 1] + k * z[j];
                k++;
            }
        }
    }
    dp[1][1] = z[1];
    for (int i = 2; i <= m; i++) {
        dp[i][1] = dp[i - 1][1] + z[i] * i;
    }
    for (int i = 0; i <= n; i++) {
        dp[1][i] = z[1];
    }

    for (int j = 2; j <= n; j++) {
        for (int i = 2; i <= m; i++) {
            dp[i][j] = dp[i - 1][j - 1] + z[i];
            for (int k = 1; k < i; k++) {
                if (dp[i][j] > dp[i - k][j - 1] + c[i - k + 1][i]) {
                    dp[i][j] = dp[i - k][j - 1] + c[i - k + 1][i];
                }
            }
        }
    }

    fout << dp[m][n];
    fin.close();
    fout.close();
}
/*
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<long long> z(m);
    for (int i = 0; i < m; i++) {
        std::cin >> z[i];
    }

    long long s = 0;
    if (n >= m) {
        for (int i = 0; i < m; i++) {
            s += z[i];
        }
        std::cout << s;
        return 0;
    }

    int k = m;
    std::vector<std::vector<std::vector<long long>>>
        dp(n, std::vector<std::vector<long long>>(m, std::vector<long long>(k, LLONG_MAX)));

    for (int i = 0; i < m; i++) {
        dp[0][i][0] = z[i];
    }
    for (int j = 0; j < n; j++) {
        dp[j][0][0] = z[0];
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j][i][0] = dp[j - 1][i - 1][k - 1] + z[0];
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            for (int y = 1; y < k; y++) {
                dp[j][i][y] = std::min(dp[j][i - 1][y - 1] + z[i] * y, dp[j - 1][i - 1][k - 1] + z[i]);
            }
        }
    }

    s = dp[n - 1][m - 1][0];
    for (int i = 1; i < k; i++) {
        if (dp[n - 1][m - 1][i] < s) {
            s = dp[n - 1][m - 1][i];
        }
    }
    std::cout << s;
}*/