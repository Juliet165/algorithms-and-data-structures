#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

int main()
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("in.txt");
    fout.open("out.txt");
    int x, y, z;
    fin >> x >> y >> z;
    std::string A, B;
    fin >> A >> B;
    int n = A.size();
    int m = B.size();
    std::vector <std::vector <int>> dp(n + 1, std::vector <int>(m + 1));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = i * x;
    }
    for (int i = 1; i <= m; i++) {
        dp[0][i] = i * y;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int delta;
            if (A[i - 1] != B[j - 1]) {
                delta = 1;
            }
            else {
                delta = 0;
            }
            dp[i][j] = std::min(dp[i - 1][j] + x, dp[i][j - 1] + y);
            dp[i][j] = std::min(dp[i - 1][j - 1] + delta * z, dp[i][j]);
        }
    }
    fout << dp[n][m];
    fin.close();
    fout.close();

}