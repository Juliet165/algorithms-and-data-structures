#include <fstream>
#include <vector>
#include <algorithm>

int binarySearchUpper(std::vector <long long>& arr, int checkedNum) {
    int left = 0;
    int right = arr.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (checkedNum <= arr[mid]) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}


int main()
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int n;
    fin >> n;
    std::vector <long long> seq(n);
    for (int i = 0; i < n; i++) {
        fin >> seq[i];
    }

    std::vector <long long> ss;
    ss.push_back(seq[0]);
    for (int i = 1; i < n; i++) {
        int j = binarySearchUpper(ss, seq[i]);
        if (j >= ss.size()) {
            ss.push_back(seq[i]);
        }
        else {
            ss[j] = seq[i];
        }
        
    }
    
    fout << ss.size();
    fin.close();
    fout.close();
}