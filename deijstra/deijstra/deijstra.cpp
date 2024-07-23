#include <fstream>
#include <vector>
#include <queue>


const long long INF = LLONG_MAX;
long long N;

long long shortestPathLength(std::vector<std::vector<std::pair<long long, long long>>>& graph) {
    long long n = graph.size();
    std::vector<long long> dist(n, INF);
    std::vector<bool> processed(n, false);
    long long start = 1;
    long long end = N;

    std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>, std::greater<std::pair<long long, long long>>> pq;
    pq.push({ 0, start });
    dist[start] = 0;

    while (!pq.empty()) {
        long long dv = pq.top().first;
        long long v = pq.top().second;
        pq.pop();

        if (processed[v]) {
            continue;
        }

        processed[v] = true;

        for (const std::pair<long long, long long> edge : graph[v]) {
            long long u = edge.first;
            long long cu = edge.second;

            if (dist[v] + cu < dist[u]) {
                dist[u] = dist[v] + cu;
                pq.push({ dist[u], u });
            }
        }
    }

    return dist[end];
}

int main() {
    std::ifstream fin;
    std::ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");

    long long n, m;
    fin >> n >> m;
    N = n;
    std::vector<std::vector<std::pair<long long, long long>>> graph(n + 1);

    for (long long i = 0; i < m; ++i) {
        long long u, v, w;
        fin >> u >> v >> w;
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });  
    }

    long long shortestLength = shortestPathLength(graph);

    fout << shortestLength;

    fin.close();
    fout.close();
}
