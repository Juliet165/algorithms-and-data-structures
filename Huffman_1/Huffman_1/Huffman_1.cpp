#include <fstream>
#include <set>

int main()
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("huffman.in");
    fout.open("huffman.out");

    int n;
    fin >> n;
    std::multiset<long long> q1;
    long long s;
    for (long long i = 0; i < n; i++) {
        fin >> s;
        q1.insert(s);
    }

    long long sum = 0;
    while (q1.size() > 1) {
        std::sort(q1.begin(), q1.end());

        long long n1 = q1[0];
        long long n2 = q1[1];

        q1.erase(q1.begin(), q1.begin() + 2);

        sum += n1 + n2;

        q1.push_back(n1 + n2);
    }
    fout << sum;
    fin.close();
    fout.close();
}