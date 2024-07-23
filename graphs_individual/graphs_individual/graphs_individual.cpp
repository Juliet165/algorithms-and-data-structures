/*#include <fstream>
#include <iostream>
#include <vector>

const int N = 1001;

std::vector<bool> part(N, false);
std::vector<bool> visited(N, false);
//int num = 1;
bool is_bipartite = true;

void dfs(int v, int n, std::vector<std::vector<bool>>& graph) {
    visited[v] = true;
    //part[v] = c;
    for (int u = 1; u <= n; u++) {
        if (graph[v][u] && u!=v) {
            if (visited[u] && part[v] == part[u]) {
                is_bipartite = false;
            }
            if (!visited[u]) {
                part[u] = !part[v];
                dfs(u, n, graph);
            }
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
    std::vector<std::vector<bool>> graph(n + 1, std::vector<bool>(n + 1, false));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            bool b;
            fin >> b;
            graph[i][j] = !b;
            
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            part[i] = true;
            dfs(i, n, graph);
        }
    }
    if (!is_bipartite) {
        fout << "NO";
        return 0;
    }
    else {
        int first = 0;
        int second = 0;
        for (int i = 1; i <= n; i++) {
            if (part[i]) {
                first++;
            }
            else {
                second++;
            }
        }
        if (first > 2 * second || second > 2 * first) {
            fout << "NO";
            return 0;
        }
        else {
            fout << "YES\n";
            for (int j = 1; j <= n; j++) {
                if (first >= second) {
                    if (part[j]) {
                        fout << j << " ";
                    }
                }
                else {
                    if (!part[j]) {
                        fout << j << " ";
                    }
                }
            }
        }
    }
}*/


/*7
1 1 1 0 1 1 1
1 1 1 0 0 1 1
1 1 1 1 0 1 1
0 0 1 1 1 1 1
1 0 0 1 1 1 1
1 1 1 1 1 1 1
1 1 1 1 1 1 1*/
/*
#include <fstream>
#include <vector>
#include <queue>

int flag = 0;
std::vector <int> count(2, 0);

bool isBipartite(std::vector<std::vector<int>>& graph, std::vector<int>& colors, int start) {
    std::queue<int> q;
    q.push(start);
    colors[start] = flag;
    count[flag]++;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int u = 1; u <= graph.size() - 1; u++) {
            if (graph[u][current]) {
                if (u == 0) {
                    break;
                }
                if (colors[u] == -1) {
                    colors[u] = 1 - colors[current];
                    count[1 - colors[current]]++;
                   
                    q.push(u);
                }
                else if (colors[u] == colors[current]) {
                    return false; 
                }
            }
            
        }
    }

    return true;
}

int main()
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");

    int n;
    fin >> n;
    std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1, false));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            bool b;
            fin >> b;
            if (b == 1) {
                graph[i][j] = 0;
            }
            else if (b == 0) {
                graph[i][j] = 1;
            }
            if (i == j) {
                graph[i][j] = 0;
            }

        }
    }

    std::vector<int> colors(n + 1, -1); 

    for (int i = 1; i <= n; ++i) {
        if (colors[i] == -1) {
            if (count[0] > count[1]) {
                flag = 1;
            }
            else {
                flag = 0;
            }
            if (!isBipartite(graph, colors, i)) {
                fout << "NO";
                return 0;
            }
        }
    }

    


    /*for (int i = 1; i <= n; ++i) {
        if (colors[i] == 0) {
            count_0++;
        }
        else if (colors[i] == 1) {
            count_1++;
        }
    }


    if (count[0] <= 2 * count[1] && count[1] <= 2 * count[0]) {
        fout << "YES\n";
        for (int j = 1; j <= n; j++) {
            if (count[1]> count[0]) {
                if (colors[j] == 1) {
                    fout << j << " ";
                }
            }
            else {
                if (colors[j] == 0) {
                    fout << j << " ";
                }
            }
        }
    }
    else {
        fout << "NO";
    }

}*/
/*
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1000000;

int n;
vector<int> g[MAXN];
bool used[MAXN];
vector<int> comp;
vector <vector<int>> components;

void dfs(int v,  vector<vector<int>> graph) {
    used[v] = true;
    comp.push_back(v);
    for (int u = 1; u <= n; u++) {
        if (!used[u] && graph[v][u]) {
            dfs(u, graph);
        }
    }
}

void find_comps(vector<vector<int>> graph) {
    for (int i = 1; i <= n; ++i){
        used[i] = false;
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            comp.clear();
            dfs(i, graph);
            components.push_back(comp);
        }
    }
}

bool isBipartite(std::vector<std::vector<int>>& graph, std::vector<int>& colors, int start) {
    std::queue<int> q;
    q.push(start);
    colors[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int u = 1; u <= graph.size() - 1; u++) {
            if (graph[u][current]) {
                if (u == 0) {
                    break;
                }
                if (colors[u] == -1) {
                    colors[u] = 1 - colors[current];
                    q.push(u);
                }
                else if (colors[u] == colors[current]) {
                    return false;
                }
            }

        }
    }

    return true;
}

int main()
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");

    //int n;
    fin >> n;
    std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1, false));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            bool b;
            fin >> b;
            graph[i][j] = b;
        }
    }
    
    find_comps(graph);
    if (components.size() > 2) {
        fout << "NO";
        return 0;
    }
    if (components.size() == 2) {
        if (components[0].size() <= 2 * components[1].size() && components[1].size() <= 2 * components[0].size()) {
            fout << "YES\n";
            if (components[0].size() >= components[1].size()) {
                for (int i = 0; i < components[0].size(); i++) {
                    fout << components[0][i] << " ";
                }
            }
            else {
                for (int i = 0; i < components[1].size(); i++) {
                    fout << components[1][i] << " ";
                }
            }
        }
        else {
            fout << "NO";
        }
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] == 1) {
                graph[i][j] = 0;
            }
            else if (graph[i][j] == 0) {
                graph[i][j] = 1;
            }
            if (i == j) {
                graph[i][j] = 0;
            }

        }
    }

    std::vector<int> colors(n + 1, -1);

    for (int i = 1; i <= n; ++i) {
        if (colors[i] == -1) {
            if (!isBipartite(graph, colors, i)) {
                fout << "NO";
                return 0;
            }
        }
    }

    int count_0 = 0;
    int count_1 = 0;

    for (int i = 1; i <= n; ++i) {
        if (colors[i] == 0) {
            count_0++;
        }
        else if (colors[i] == 1) {
            count_1++;
        }
    }

    if (count_1 <= 2 * count_0 && count_0 <= 2 * count_1) {
        fout << "YES\n";
        for (int j = 1; j <= n; j++) {
            if (count_1 > count_0) {
                if (colors[j] == 1) {
                    fout << j << " ";
                }
            }
            else {
                if (colors[j] == 0) {
                    fout << j << " ";
                }
            }
        }
    }
    else {
        fout << "NO";
    }

}
*/
#include <fstream>
#include <iostream>
#include <vector>

const int N = 1001;

std::vector<bool> part(N, false);
std::vector<bool> visited(N, false);
//int num = 1;
bool is_bipartite = true;

void dfs(int v, int n, std::vector<std::vector<bool>>& graph) {
    visited[v] = true;
    //part[v] = c;
    for (int u = 1; u <= n; u++) {
        if (graph[v][u] && u != v) {
            if (visited[u] && part[v] == part[u]) {
                is_bipartite = false;
            }
            if (!visited[u]) {
                part[u] = !part[v];
                dfs(u, n, graph);
            }
        }
    }
}

void dfs2(int v, const std::vector<std::vector<int>>& adjacency_matrix, std::vector<bool>& visited, std::vector<int>& component) {
    visited[v] = true;
    component.push_back(v);

    for (int u = 0; u < adjacency_matrix.size(); ++u) {
        if (adjacency_matrix[v][u] == 1 && !visited[u]) {
            dfs(u, adjacency_matrix, visited, component);
        }
    }
}

std::vector<std::vector<int>> find_connected_components(std::vector<std::vector<int>>& adjacency_matrix) {
    int n = adjacency_matrix.size();
    std::vector<bool> visited(n, false);
    std::vector<std::vector<int>> components;

    for (int vertex = 0; vertex < n; ++vertex) {
        if (!visited[vertex]) {
            std::vector<int> component;
            dfs2(vertex, adjacency_matrix, visited, component);
            components.push_back(component);
        }
    }
    return components;
}

std::pair<std::vector<int>, std::vector<int>> divide_into_teams(const std::vector<std::vector<int>>& components) {
    std::vector<int> team1, team2;
    int total_size = 0;

    std::vector<std::vector<int>> sorted_components = components;
    std::sort(sorted_components.begin(), sorted_components.end(), [](const auto& a, const auto& b) {
        return a.size() > b.size();
        });

    for (const auto& component : sorted_components) {
        if (team1.size() <= team2.size()) {
            team1.insert(team1.end(), component.begin(), component.end());
        }
        else {
            team2.insert(team2.end(), component.begin(), component.end());
        }

        total_size += component.size();
    }

int main()
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");

    int n;
    fin >> n;
    std::vector<std::vector<bool>> graph(n + 1, std::vector<bool>(n + 1, false));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            bool b;
            fin >> b;
            graph[i][j] = !b;

        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            part[i] = true;
            dfs(i, n, graph);
        }
    }
    if (!is_bipartite) {
        fout << "NO";
        return 0;
    }
    else {
        std::vector<std::vector<int>> comps = find_connected_components(graph);
        auto teams = divide_into_teams(comps);

        int first = teams.first.size();
        int second = teams.second.size();
        /*for (int i = 1; i <= n; i++) {
            if (part[i]) {
                first++;
            }
            else {
                second++;
            }
        }*/
        if (first > 2 * second || second > 2 * first) {
            fout << "NO";
            return 0;
        }
        else {
            fout << "YES\n";
            for (int j = 1; j <= n; j++) {
                if (first >= second) {
                    if (part[j]) {
                        fout << j << " ";
                    }
                }
                else {
                    if (!part[j]) {
                        fout << j << " ";
                    }
                }
            }
        }
    }

}