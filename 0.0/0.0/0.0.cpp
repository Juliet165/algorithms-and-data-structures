#include <fstream>
#include <unordered_set>

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    std::unordered_set <int> data;
    int n;

    while (!fin.eof())
    {
        fin >> n;
        data.insert(n);
    }

    long long sum = 0;
    for (auto itr = data.begin(); itr != data.end(); itr++)
    {
        sum += *itr;
    }

    fout << sum;
}