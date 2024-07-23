/*#include <fstream>
#include <vector>
#include <algorithm>

const int N = 1001;

std::vector<bool> part(N, false);
std::vector<bool> visited(N, false);
std::vector<bool> visited2(N, false);
//int num = 1;
bool is_bipartite = true;

void dfs(int v, int n, std::vector<std::vector<int>>& graph) {
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
    visited2[v] = true;
    component.push_back(v);

    for (int u = 0; u < adjacency_matrix.size(); ++u) {
        if (adjacency_matrix[v][u] == 1 && !visited2[u]) {
            dfs2(u, adjacency_matrix, visited2, component);
        }
    }
}

std::vector<std::vector<int>> find_connected_components(std::vector<std::vector<int>> adjacency_matrix) {
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

void divide_component(std::vector<int>& component) {
    int n = component.size();
    for (int i = 0; i < n; ++i) {
        component[i] = i % 2;  // Пронумеровать доли 0 и 1
    }
}

// Функция для объединения компонент связности в граф с минимальной разностью размеров долей
void combine_components(const std::vector<std::vector<int>>& components) {
    std::vector<int> combined_graph;

    for (const auto& component : components) {
        std::vector<int> sorted_component = component;
        std::sort(sorted_component.begin(), sorted_component.end());

        int component_size = sorted_component.size();
        int half_size = (component_size + 1) / 2;

        for (int i = 0; i < half_size; ++i) {
            combined_graph.push_back(sorted_component[i]);
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
        //auto teams = divide_into_teams(comps);

        //int first = teams.first.size();
        //int second = teams.second.size();
        /*for (int i = 1; i <= n; i++) {
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
        }*/

/*
#include <fstream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using adj_list = vector<vector<int>>;
using find_scc_result = pair<int, vector<int>>;

// найти все сильно связные компоненты в графе
// https://github.com/larandaA/alg-ds-snippets/blob/master/dfs-bfs.md#сильно-связные-компоненты
find_scc_result find_strongly_connected_components(adj_list& adjacency_list, adj_list& transposed_adjacency_list);

// разделить векор (индекс - номер, значение - компонента) на несколько векторов
vector<vector<int>> separate_components(int n_components, vector<int>& vertex_components);

// разбить компоненту на доли
// возвр. - двудольность графа
bool partition_component(int v, int component, vector<int>& components, adj_list& adjacency_list, vector<bool>& visited,
    vector<bool>& part);

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "NO\n";
        return 0;
    }
    adj_list adjacency_list(n, vector<int>());
    adj_list transposed_adjacency_list(n, vector<int>());
    int tmp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> tmp;
            if (!tmp && i != j) { // мы работаем с обратным графом: нет ребра - знакомы
                adjacency_list[i].emplace_back(j);
                transposed_adjacency_list[j].emplace_back(i);
            }
        }
    }
    auto [n_components, vertex_components] = find_strongly_connected_components(adjacency_list,
        transposed_adjacency_list);
    auto connected_components = separate_components(n_components, vertex_components);
    vector<pair<vector<int>, vector<int>>> component_partitions(n_components);

    // разделяем все компоненты связности на доли
    // если хоть одна из них не двудольный граф, то решения нет
    for (int i = 0; i < n_components; ++i) {
        vector<bool> visited(n);
        vector<bool> part(n);
        auto result = partition_component(connected_components[i][0], i, vertex_components, adjacency_list, visited,
            part);
        if (!result) {
            cout << "NO\n";
            return 0;
        }
        for (int j = 0; j < part.size(); ++j) {
            if (vertex_components[j] == i) {
                if (part[j])
                    component_partitions[i].first.emplace_back(j);
                else
                    component_partitions[i].second.emplace_back(j);
            }
        }
        visited.assign(n, false);
    }


    auto sort_predicate = [](const pair<vector<int>, vector<int>>& A, const pair<vector<int>, vector<int>>& B) {
        return max(A.first.size(), A.second.size()) > max(B.first.size(), B.second.size());
    };
    sort(component_partitions.begin(), component_partitions.end(), sort_predicate);

    vector<int> teamA;
    vector<int> teamB;
    teamA.reserve(n);
    teamB.reserve(n);

    // Собираем команды жадным алгоритмом
    // Начинаем с самой крупной доли и всегда добавляем большую долю к меньшей команде, а противоположную - к большей
    for (auto& cp : component_partitions) {
        auto& [p1, p2] = cp;
        if (teamA.size() > teamB.size()) {
            if (p1.size() > p2.size()) {
                teamA.insert(teamA.end(), p2.begin(), p2.end());
                teamB.insert(teamB.end(), p1.begin(), p1.end());
            }
            else {
                teamA.insert(teamA.end(), p1.begin(), p1.end());
                teamB.insert(teamB.end(), p2.begin(), p2.end());
            }
        }
        else {
            if (p1.size() > p2.sie()) {
                teamA.insert(teamA.end(), p1.begin(), p1.end());
                teamB.insert(teamB.end(), p2.begin(), p2.end());
            }
            else {
                teamA.insert(teamA.end(), p2.begin(), p2.end());
                teamB.insert(teamB.end(), p1.begin(), p1.end());
            }
        }
    }
    if (teamA.size() < teamB.size()) {
        swap(teamA, teamB);
    }
    if ((double)teamA.size() / (double)teamB.size() > 2.0) {
        cout << "NO\n";
        return 0;
    }
    sort(teamA.begin(), teamA.end());
    cout << "YES\n";
    for (int i = 0; i < teamA.size(); ++i) {
        cout << teamA[i] + 1 << " \n"[i == teamA.size() - 1];
    }
}


void dfs1(int v, adj_list& adjacency_list, vector<bool>& visited, vector<int>& ordered) {
    visited[v] = true;
    for (auto& u : adjacency_list[v]) {
        if (!visited[u])
            dfs1(u, adjacency_list, visited, ordered);
    }
    ordered.emplace_back(v);
}


void
dfs2(int v, adj_list& adjacency_list_transposition, vector<bool>& visited, vector<int>& components, int n_component) {
    visited[v] = true;
    components[v] = n_component;
    for (auto& u : adjacency_list_transposition[v]) {
        if (!visited[u]) {
            dfs2(u, adjacency_list_transposition, visited, components, n_component);
        }
    }
}


find_scc_result find_strongly_connected_components(adj_list& adjacency_list, adj_list& transposed_adjacency_list) {
    size_t n = adjacency_list.size();
    vector<bool> visited(n);
    vector<int> ordered(0);
    for (int v = 0; v < n; ++v) {
        if (!visited[v])
            dfs1(v, adjacency_list, visited, ordered);
    }
    visited.assign(n, false);
    int n_components = 0;
    vector<int> component(n);
    for (auto iv = rbegin(ordered); iv != rend(ordered); ++iv) {
        if (!visited[*iv]) {
            dfs2(*iv, transposed_adjacency_list, visited, component, n_components);
            ++n_components;
        }
    }
    return { n_components, component };
}


vector<vector<int>> separate_components(int n_components, vector<int>& vertex_components) {
    vector<vector<int>> connected_components(n_components);
    for (int i = 0; i < vertex_components.size(); ++i) {
        connected_components[vertex_components[i]].emplace_back(i);
    }
    return connected_components;
}


bool partition_component(int v, int component, vector<int>& components, adj_list& adjacency_list, vector<bool>& visited,
    vector<bool>& part) {
    visited[v] = true;
    bool is_bipartite = true;
    for (auto& u : adjacency_list[v]) {
        if (components[u] == component) {
            if (visited[u] && part[u] == part[v]) {
                is_bipartite = false;
            }
            if (!visited[u]) {
                part[u] = !part[v];
                is_bipartite = partition_component(u, component, components, adjacency_list, visited, part);
            }
        }
    }
    return is_bipartite;
}*/

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

using Graph = vector<vector<int>>;
vector <pair <vector<int>, vector<int>>> parts;

// Функция для выполнения DFS и поиска компоненты связности
void dfs(int v, const Graph& adjacency_matrix, vector<bool>& visited, vector<int>& component) {
    visited[v] = true;
    component.push_back(v);

    for (int u = 1; u < adjacency_matrix.size(); ++u) {
        if (adjacency_matrix[v][u] == 1 && !visited[u]) {
            dfs(u, adjacency_matrix, visited, component);
        }
    }
}

// Функция для поиска компонент связности в графе
vector<vector<int>> findConnectedComponents(const Graph& adjacency_matrix) {
    int n = adjacency_matrix.size();
    vector<bool> visited(n, false);
    vector<vector<int>> components;

    for (int v = 1; v < n; ++v) {
        if (!visited[v]) {
            vector<int> component;
            dfs(v, adjacency_matrix, visited, component);
            components.push_back(component);
        }
    }

    return components;
}

bool isBipartite(const vector<int>& component, const vector<vector<int>>& adjacency_matrix, vector<int>& color) {
    int n = adjacency_matrix.size();

    // Инициализация массива меток (-1 - не посещена, 0 - первая доля, 1 - вторая доля)
    fill(color.begin(), color.end(), -1);

    // Первая вершина помечается первой долей
    color[component[0]] = 0;

    // Очередь для BFS
    vector<int> queue;
    queue.push_back(component[0]);

    while (!queue.empty()) {
        int u = queue.front();
        queue.erase(queue.begin());

        for (int v : component) {
            if (adjacency_matrix[u][v] == 1) {
                // Если вершина уже посещена и метка совпадает, граф недвудольный
                if (color[v] != -1 && color[v] == color[u]) {
                    return false;
                }

                // Если вершина не посещена, помечаем её другой долей и добавляем в очередь
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    queue.push_back(v);
                }
            }
        }
    }
    vector <int> zeros;
    vector <int> ones;
    for (int v : component) {
        if (color[v] == 1) {
            ones.push_back(v);
        }
        else if (color[v] == 0) {
            zeros.push_back(v);
        }
    }
    if (zeros.size() > ones.size()) {
        swap(zeros, ones);
    }
    parts.push_back({ zeros, ones });

    // Если все вершины посещены и граф не содержит неоднозначных меток, то граф двудольный
    return true;
}

pair <vector <int>, vector <int>> mergeConnectedComponents() {
    vector <int> teamA;
    vector <int> teamB;

    auto sort_predicate = [](const auto& A, const auto& B) {
        return max(A.first.size(), A.second.size()) > max(B.first.size(), B.second.size());
    };

    // Сортировка вектора пар с использованием лямбда-функции
    sort(parts.begin(), parts.end(), sort_predicate);

    for (pair <vector<int>, vector<int>>p : parts) {
        if (teamA.size() >= teamB.size()) {
            teamA.insert(teamA.end(), p.second.begin(), p.second.end());
            teamB.insert(teamB.end(), p.first.begin(), p.first.end());
        }
        else if (teamA.size() < teamB.size()) {
            teamA.insert(teamA.end(), p.first.begin(), p.first.end());
            teamB.insert(teamB.end(), p.second.begin(), p.second.end());
        }
    }
    if (teamA.size() < teamB.size()) {
        swap(teamA, teamB);
    }
    return {teamA, teamB};
}

int main() {
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

    vector<vector<int>> components = findConnectedComponents(graph);
    vector<int> color(n + 1, -1);
    for (auto& component : components) {
        if (!isBipartite(component, graph, color)) {
            fout << "NO"; 
            return 0;
        }
    }
    pair <vector <int>, vector <int>> bipartiteGraph = mergeConnectedComponents();
    int n1 = bipartiteGraph.first.size();
    int n2 = bipartiteGraph.second.size();
    if (n1 > 2 * n2 || n2 > 2 * n1) {
        fout << "NO";
        return 0;
    }
    else {
        fout << "YES\n";
        sort(bipartiteGraph.first.begin(), bipartiteGraph.first.end());
        for (int i = 0; i < bipartiteGraph.first.size(); ++i) {
            fout << bipartiteGraph.first[i] << " ";
        }
    }


    /*vector<vector<int>> components = findConnectedComponents(graph);
    vector<int> color(n + 1, -1);
    for (auto& component : components) {
        if (isBipartite(component, graph, color)) {
            fout << "The component is bipartite.\n";
            for (int i = 0; i < component.size(); ++i) {
                fout << "Vertex " << component[i] << ": Color " << color[component[i]] << endl;
            }
        }
        else {
            fout << "The component is not bipartite.\n";
        }
    }


    pair <vector <int>, vector <int>> bipartiteGraph = mergeConnectedComponents();
    fout << "Vertex Partition" << endl;
    fout << "First part:\n";
    for (int i = 0; i < bipartiteGraph.first.size(); ++i) {
        fout << bipartiteGraph.first[i] << "    ";
    }
    fout << "\nSecond part:\n";
    for (int i = 0; i < bipartiteGraph.second.size(); ++i) {
        fout << bipartiteGraph.second[i] << "    ";
    }*/


}

/*6
0 1 1 0 1 1
1 0 1 0 1 1 
1 1 0 0 1 1 
0 0 0 0 1 1 
1 1 1 1 0 1
1 1 1 1 1 0*/