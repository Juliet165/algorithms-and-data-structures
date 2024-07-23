/*#include <fstream>
#include <vector>
int maxN = 1000000;
int num;
std::vector <int> dsu(maxN, -1);

int findLeader(int n) {
    if (dsu[n] < 0) {
        return n;
    }
    return dsu[n] = findLeader(dsu[n]);
}

void makeRoad(int a, int b) {
    int leaderA = findLeader(a);
    int leaderB = findLeader(b);

    if (leaderA != leaderB) {
        if (dsu[leaderA] < dsu[leaderB]) {
            std::swap(leaderA, leaderB);
        }
        dsu[leaderA] += dsu[leaderB];
        dsu[leaderB] = leaderA;
        num--;
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
    num = n;

    int m;
    fin >> m;
    std::vector <std::pair<int, int>> roads(m + 1);

    int q;
    fin >> q;
    std::vector <int> query(q + 1);

    for (int i = 1; i <= m; i++) {
        fin >> roads[i].first >> roads[i].second;
    }
    for (int i = 1; i <= q; i++) {
        fin >> query[i];
    }
    dsu.resize(n + 1);
    std::vector <int> res(q + 1, -1);
    if (q == m) {
        res[q] = 0;
        for (int i = q; i > 0; i--) {
            makeRoad(roads[query[i]].first, roads[query[i]].second);
            if (num > 1) {
                //res.push_back(0);
                res[i - 1] = 0;
            }
            else {
                res[i - 1] = 1;
                break;
            }
            //res.push_back(1);
        }
    }
    else {
        for (int i = 1; i <= m; i++) {
            bool found = false;
            for (int j = 1; j <= q; j++) {
                if (query[j] == i) found = true;
            }
            if (!found) {
                makeRoad(roads[i].first, roads[i].second);
            }
        }
        bool cont = true;
        if (num > 1) {
            //res.push_back(0);
            res[q] = 0;
        }
        else {
            res[q] = 1;
            cont = false;
        }
        
        if (cont) {
            for (int i = q; i > 0; i--) {
                makeRoad(roads[query[i]].first, roads[query[i]].second);
                if (num > 1) {
                    //res.push_back(0);
                    res[i - 1] = 0;
                }
                else {
                    res[i - 1] = 1;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        if (res[i] == -1) {
            fout << 1;
        }
        else {
            fout << res[i];
        }
    }

    fin.close();
    fout.close();
}*/

/*
#include <fstream>
#include <vector>

int num;
//std::vector <int> dsu(-1);

int findLeader(int n, std::vector <int> &dsu) {
    if (dsu[n] < 0) {
        return n;
    }
    return dsu[n] = findLeader(dsu[n], dsu);
}

std::vector <int> makeRoad(int a, int b, std::vector <int>& dsu) {
    int leaderA = findLeader(a, dsu);
    int leaderB = findLeader(b, dsu);

    if (leaderA != leaderB) {
        if (dsu[leaderA] < dsu[leaderB]) {
            std::swap(leaderA, leaderB);
        }
        dsu[leaderA] += dsu[leaderB];
        dsu[leaderB] = leaderA;
        num--;
    }
    return dsu;
}

int main()
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int n;
    fin >> n;
    num = n;

    int m;
    fin >> m;
    std::vector <std::pair<int, int>> roads(m + 1);
    std::vector <bool> destroyed(m + 1, false);

    int q;
    fin >> q;
    std::vector <int> query(q + 1);

    for (int i = 1; i <= m; i++) {
        fin >> roads[i].first >> roads[i].second;
    }
    for (int i = 1; i <= q; i++) {
        fin >> query[i];
        destroyed[i] = true;
    }
    std::vector <int> dsu(n + 1, -1);
    //dsu.resize(n + 1);
    std::vector <int> res(q + 1, -1);
    if (q == m) {
        res[q] = 0;
        for (int i = q; i > 0; i--) {
            dsu = makeRoad(roads[query[i]].first, roads[query[i]].second, dsu);
            if (num > 1) {
                //res.push_back(0);
                res[i - 1] = 0;
            }
            else {
                res[i - 1] = 1;
                break;
            }
            //res.push_back(1);
        }
    }
    else {

        for (int i = 1; i <= m; i++) {
            if (!destroyed[i]) {
                dsu = makeRoad(roads[i].first, roads[i].second, dsu);
            }
        }
        bool cont = true;
        if (num > 1) {
            //res.push_back(0);
            res[q] = 0;
        }
        else {
            res[q] = 1;
            cont = false;
        }

        if (cont) {
            for (int i = q; i > 0; i--) {
                dsu = makeRoad(roads[query[i]].first, roads[query[i]].second, dsu);
                if (num > 1) {
                    //res.push_back(0);
                    res[i - 1] = 0;
                }
                else {
                    res[i - 1] = 1;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        if (res[i] == -1) {
            fout << 1;
        }
        else {
            fout << res[i];
        }
    }

    fin.close();
    fout.close();
}*/

#include <fstream>
#include <vector>
int maxN = 1000000;
int num;
std::vector <int> dsu(maxN, -1);

int findLeader(int n) {
    if (dsu[n] < 0) {
        return n;
    }
    return dsu[n] = findLeader(dsu[n]);
}

void makeRoad(int a, int b) {
    int leaderA = findLeader(a);
    int leaderB = findLeader(b);

    if (leaderA != leaderB) {
        if (dsu[leaderA] < dsu[leaderB]) {
            std::swap(leaderA, leaderB);
        }
        dsu[leaderA] += dsu[leaderB];
        dsu[leaderB] = leaderA;
        num--;
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
    num = n;

    int m;
    fin >> m;
    std::vector <std::pair<int, int>> roads(m + 1);
    std::vector <bool> notDestr(m + 1, true);

    int q;
    fin >> q;
    std::vector <int> query(q + 1);

    for (int i = 1; i <= m; i++) {
        fin >> roads[i].first >> roads[i].second;
    }
    for (int i = 1; i <= q; i++) {
        fin >> query[i];
        notDestr[query[i]] = false;
    }
    dsu.resize(n + 1);
    std::vector <int> res (q+1, -1);
    for (int i = 1; i <= m; i++) {
        if (notDestr[i]) {
            makeRoad(roads[i].first, roads[i].second);
        }
    }
    for (int i = q; i > 0; i--) {
        if (num > 1) {
            res[i] = 0;
        }
        else {
            res[i] = 1;
            break;
        }
        makeRoad(roads[query[i]].first, roads[query[i]].second);
    }

    for (int i = 1; i <= q; i++) {
        if (res[i] == -1) {
            fout << 1;
        }
        else {
            fout << res[i];
        }
    }

    fin.close();
    fout.close();
}