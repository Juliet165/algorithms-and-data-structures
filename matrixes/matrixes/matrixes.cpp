/*#include <iostream>
#include <vector>

int main()
{
    int s;
    std::cin >> s;
    std::vector <std::pair<int, int>> v(s + 1);
    for (int i = 1; i <= s; i++) {
        std::cin >> v[i].first >> v[i].second;
    }
    std::vector <std::vector<int>> dp(s + 1, std::vector<int>(s + 1));
    //dp[1][1] = 0;
    dp[0][0] = INT16_MAX;
    dp[s][s] = 0;
    for (int i = 1; i < s; i++) {
        dp[i][i] = 0;
        dp[i][i + 1] = v[i].first * v[i].second * v[i + 1].second;
        for (int j = i; j < s; j++) {
            //dp[i][j] = dp[i][i] + dp[i + 1][j] + v[i].first * v[i].second + v[j].second;
            for (int k = i; k < j; k++) {
                int d = dp[i][k] + dp[k + 1][j] + v[i].first * v[k].second + v[j].second;
                if (d < dp[i][j]) {
                    dp[i][j] = d;
                }   
            }
        }
    }
    std::cout << dp[1][s];
}
*/

#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>

int main()
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");

    int s;
    fin >> s;
    std::vector <std::pair<int, int>> v(s);
    for (int i = 0; i < s; i++) {
        fin >> v[i].first >> v[i].second;
    }
    std::vector <std::vector<int>> dp(s, std::vector<int>(s));
    dp[0][0] = 0;
    for (int r = 2; r <= s; r++) {
        for (int i = 0; i <= s - r; i++) {
            int j = i + r - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k + 1][j] + v[i].first * v[k].second * v[j].second);
            }
        }
    }
    fout << dp[0][s-1];
    fin.close();
    fout.close();
} 