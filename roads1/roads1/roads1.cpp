#include <fstream>
#include <vector>
/*
int main()
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int n;
    fin >> n;
    int q;
    fin >> q;
    std::vector <int> dsu(n + 1, -1);
    int num = n;
    for (int i = 1; i <= q; i++) {
        int first, second;
        fin >> first >> second;
        if (dsu[first] == -1 && dsu[second] == -1) {
            dsu[first]--;
            dsu[second] = first;
            num--;
        }
        else if (dsu[first] != -1 && dsu[second] == -1) {
            dsu[second] = first;
            while (dsu[first] > 0) {
                first = dsu[first];
            }
            dsu[first]--;
            num--;
        }
        else if (dsu[second] != -1 && dsu[first] == -1) {
            dsu[first] = second;
            while (dsu[second] > 0) {
                second = dsu[second];
            }
            dsu[second]--;
            num--;
        }
        else if (dsu[first] != -1 && dsu[second] != -1) {
            while (dsu[first] > 0) {
                first = dsu[first];
            }
            while (dsu[second] > 0) {
                second = dsu[second];
            }
            if (first == second) {
             
            }
            else if (dsu[first] < dsu[second]) {
                dsu[first] += dsu[second];
                dsu[second] = first;
                num--;
            }
            else {
                dsu[second] += dsu[first];
                dsu[first] = second;
                num--;
            }
        }
        fout << num << std::endl;
    }
    fin.close();
    fout.close();
}
*/
int findLeader(std::vector<int>& d, int n) {
    if (d[n] < 0) {
        return n;
    }
    return d[n] = findLeader(d, d[n]);
}

int main()
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int n;
    fin >> n;
    int q;
    fin >> q;
    std::vector <int> dsu(n + 1, -1);
    int num = n;
    for (int i = 1; i <= q; i++) {
        int first, second;
        fin >> first >> second;
        if (findLeader(dsu, first) != findLeader(dsu, second)) {
            if (dsu[findLeader(dsu, first)] < dsu[findLeader(dsu, second)]) {
                dsu[findLeader(dsu, first)] += dsu[findLeader(dsu, second)];
                dsu[findLeader(dsu, second)] = findLeader(dsu, first);
                num--;
            }
            else {
                dsu[findLeader(dsu, second)] += dsu[findLeader(dsu, first)];
                dsu[findLeader(dsu, first)] = findLeader(dsu, second);
                num--;
            }
        }
        fout << num << std::endl;
    }
    fin.close();
    fout.close();
}