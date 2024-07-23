#include <iostream>
#include <vector>
#include <fstream>

int main()
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    
    int n;
    fin >> n;
    std::vector <int> heap(n + 1);
    for (int i = 1; i <= n; i++) {
        fin >> heap[i];
    }

    for (int i = 1; i <= n / 2; i++) {
        if (2 * i <= n && heap[i] > heap[2 * i]) {
            fout << "No";
            return 0;
        }
        if (2 * i + 1<= n && heap[i] > heap[2 * i + 1]) {
            fout << "No";
            return 0;
        }
    }
    fout << "Yes";
    fin.close();
    fout.close();
}
