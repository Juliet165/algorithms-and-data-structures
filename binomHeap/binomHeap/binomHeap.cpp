#include <iostream>
#include <vector>

//13 = 1+4+8
// 0 2 3

int main()
{
    /*std::ifstream fin;
    std::ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");*/

    long long n;
    std::cin >> n;
    std::vector <long long> s;
    
    while (n) {
        s.push_back(n % 2);
        n /= 2;
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 1) {
            std::cout << i;
        }
    }
    //fin.close();
    //fout.close();
}
