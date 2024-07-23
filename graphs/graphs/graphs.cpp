#include <fstream>
#include <vector>

/*матрица смежности
int main()
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int n, m;
    fin >> n >> m;
    std::vector<std::vector<int>> smez(n + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        int u, v;
        fin >> u >> v;
        smez[u][v] = 1;
        smez[v][u] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fout << smez[i][j] << " ";
        }
        fout << "\n";
    }
}*/

/*канонический вид по ребрам
int main() 
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int n;
    fin >> n;
    std::vector <int> kanon(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        fin >> u >> v;
        kanon[v] = u;
    }
    for (int j = 1; j <= n; j++) {
        fout << kanon[j] << " ";
    }
}*/

/*список смежности
int main()
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int n, m;
    fin >> n >> m;
    std::vector<std::vector<int>> smezList(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        fin >> u >> v;
        smezList[v].push_back(u);
        smezList[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        fout << smezList[i].size() << " ";
        for (int j = 0; j < smezList[i].size(); ++j) {
            fout << smezList[i][j] << " ";
        }
        fout << std::endl;
    }
}*/

int main()
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int n;
    fin >> n;
    std::vector <int> kanon(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int bit;
            fin >> bit;
            if (bit == 1) {
                kanon[j] = i;
            }
        }
    }
    for (int j = 1; j <= n; j++) {
        fout << kanon[j] << " ";
    }
}