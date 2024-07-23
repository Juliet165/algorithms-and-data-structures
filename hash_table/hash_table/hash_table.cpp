#include <fstream>
#include <vector>

int main()
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int m, c, n;
    fin >> m >> c >> n;

    std::vector <long long> hash(m, -1);

    for (int j = 0; j < n; ++j) {
        long long key;
        fin >> key;

        //int i = 0;
        //int h = (key % m) % m;

        for (int r = 0; r < m; r++) {
            int h = ((key % m) + c * r) % m;
            if (hash[h] == -1) {
                hash[h] = key;
                break;
            }
            if (hash[h] == key) {
                break;
            }
        }
        
    }

    for (int i = 0; i < m; ++i) {
        fout << hash[i] << " ";
    }

}
