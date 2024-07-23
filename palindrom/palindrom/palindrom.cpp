#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{

    std::ifstream fin;
    std::ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");

    std::string line;
    fin >> line;
    int n = line.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        dp[i][i] = 1;
        if (line[i - 1] == line[i]) {
            dp[i - 1][i] = 2;
        }
        else {
            dp[i - 1][i] = 1;
        }
    }
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i < n - l + 1; i++) {
            int j = i + l - 1;
            if (line[i] == line[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else {
                dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    std::string result;
    int i = 0, j = n - 1;
    while (i < j) {
        if (line[i] == line[j]) {
            result += line[i];
            i++;
            j--;
        }
        else if (dp[i + 1][j] > dp[i][j - 1]) {
            i++;
        }
        else {
            j--;
        }
    }
    std::string second = result;
    if(i == j) {
        result += line[i];
    }

    std::reverse(second.begin(), second.end());
    result += second;

    fout << dp[0][n - 1] << std::endl;
    fout << result;
    fin.close();
    fout.close();
}