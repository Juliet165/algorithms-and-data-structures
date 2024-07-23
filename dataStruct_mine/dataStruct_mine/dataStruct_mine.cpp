#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>  

using namespace std;

const int MAXN = 10000;

int n, m, k;
vector<vector<int>> labyrinth(MAXN, vector<int>(MAXN, 1));

vector<int> enters(MAXN);
vector<int> exits(MAXN);

enum dirs { righ, straight, lef, bak };

int points;

bool search(stack<pair<int, int>>& route, dirs dir, int person)
{
    if (points == m) {
        return false;
    }
    pair<int, int> pos = make_pair(route.top().first, route.top().second);
    if (dir == righ) {
        pos.second--;
    }
    if (dir == lef) {
        pos.second++;
    }
    if (dir == bak) {
        pos.first--;
    }
    if (dir == straight) {
        pos.first++;
    }
    if (pos.first < 1 || pos.first > n || pos.second < 1 || pos.second > m)
        return false;
    if (labyrinth[pos.first][pos.second] != 0 && !(pos.first == n && (labyrinth[pos.first][pos.second] != 1 &&
        labyrinth[pos.first][pos.second] != person + 1))) {
        return false;
    }
    else
    {
        route.push(pos);
        labyrinth[pos.first][pos.second] = 1;
        if (pos.first == n && find(exits.begin(), exits.end(), pos.second) == exits.end()) {
            points++;
        }
        if (pos.first == n && find(exits.begin(), exits.end(), pos.second) != exits.end()) {
            return true;
        }
        else
        {
            std::vector <dirs> priority;
            if (dir == righ) {
                priority = { bak, righ, straight };
            }
            if (dir == lef) {
                priority = { straight, lef, bak };
            }
            if (dir == bak) {
                priority = { righ, bak, lef };
            }
            if (dir == straight) {
                priority = { righ, straight, lef };
            }
            bool found = true;
            for (int i = 0; i < 3; i++)
            {
                found = search(route, priority[i], person);
                if (found) {
                    return true;
                }
            }
            labyrinth[pos.first][pos.second] = 0;
            route.pop();
            return false;
        }
    }
}

stack<pair<int, int>> findRoute(int person)
{
    stack<pair<int, int>> r;
    r.push({ 0, enters[person] });

    if (!search(r, straight, person))
        throw - 1;
    return r;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin >> n >> m >> k;

    for (int i = 1; i <= k; ++i) {
        fin >> enters[i];
    }

    for (int i = 1; i <= k; ++i) {
        fin >> exits[i];
    }
    points = k;
    for (int i = 1; i <= m; i++) {
        if ((labyrinth[n][i] == 0) && (labyrinth[n][i + 1] == 1) && (labyrinth[n][i - 1] == 1) && (labyrinth[n - 1][i] == 1)) {
            points++;
        }
    }
    int temp = points;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            fin >> labyrinth[i][j];
        }
    }
    int maxPeople = 0;
    for (int i = 1; i <= k; i++) {
        points = temp;
        try {
            stack<pair<int, int>> road = findRoute(i);
            while (!road.empty())
            {
                pair<int, int> pos = road.top();
                labyrinth[pos.first][pos.second] = i + 1;
                road.pop();
            }
            maxPeople++;
        }
        catch (...) {

        }
    }

    fout << maxPeople << endl;


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            fout << labyrinth[i][j] << " ";
        }
        fout << endl;
    }

    fin.close();
    fout.close();

    return 0;
}