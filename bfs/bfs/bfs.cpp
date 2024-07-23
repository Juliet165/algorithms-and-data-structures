#include <fstream>
#include <vector>
#include <queue>

const int N = 101;

//std::vector<std::vector<int>> graph(N + 1, std::vector<int>(N + 1, 0));
std::vector<int> res(N, 0);
std::vector<bool> visited(N, false);
int num = 1;

void bfs(int first, int n, std::vector<std::vector<int>> &graph) {
    std::queue<int> q;
    res[first] = num++;
    visited[first] = true;
    q.push(first);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u = 1; u <= n; u++) {
            if (!visited[u] && graph[v][u]) {
                visited[u] = true;
                res[u] = num;
                q.push(u);
                num++;
            }
        }
    }
}

int main() {
    std::ifstream fin;
    std::ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int n;
    fin >> n;
    std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> graph[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            bfs(i, n, graph);
        }
    }

    for (int i = 1; i <= n; ++i) {
        fout << res[i] << " ";
    }

}
/*
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int ind = 1;

void bfs(int start, int n, vector<vector<int>>& s, vector<bool>& vis, vector<int>& r) {
    queue<int> q;
    r[start] = ind;
    ind += 1;
    vis[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u = 1; u <= n; u++) {
            if (s[v][u] && !vis[u]) {
                vis[u] = true;
                r[u] = ind;
                ind++;
                q.push(u);
            }
        }
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;
    vector<vector<int>> smez(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> smez[i][j];
        }
    }
    vector<bool> viseted(n + 1, false);
    vector<int> result(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (!viseted[i]) {
            bfs(i, n, smez, viseted, result);
        }
    }

    for (int i = 1; i <= n; i++) {
        fout << result[i] << ' ';
    }

    fin.close();
    fout.close();
    return 0;
}*/