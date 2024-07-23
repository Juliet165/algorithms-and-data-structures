#include <fstream>
#include <vector>

const int N = 101;

std::vector<int> res(N, 0);
std::vector<bool> visited(N, false);
int num = 1;

void dfs(int v, int n, std::vector<std::vector<int>>& graph) {
    visited[v] = true;
    res[v] = num++;
    
    for (int u = 1; u <= n; u++) {
        if (!visited[u] && graph[v][u]) {
            dfs(u, n, graph);
        }
    }
}

int main()
{
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
            dfs(i, n, graph);
        }
    }

    for (int i = 1; i <= n; ++i) {
        fout << res[i] << " ";
    }
}