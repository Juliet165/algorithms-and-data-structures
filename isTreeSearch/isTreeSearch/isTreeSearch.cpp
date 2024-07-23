#include <vector>
#include <fstream>

int main()
{
	std::ifstream fin;
	std::ofstream fout;
	fin.open("bst.in");
	fout.open("bst.out");
	int quantity;
	fin >> quantity;
	std::vector <long long> key(quantity + 1);
	std::vector <long long> parent(quantity + 1);
	std::vector <std::string> LR(quantity + 1);
	std::vector <std::pair<long long, long long>> interval(quantity + 1);
	
	fin >> key[1];
	interval[1].first = LLONG_MIN;
	interval[1].second = LLONG_MAX;
	LR[1] = "none";
	parent[0] = LLONG_MIN;

	for (int i = 2; i <= quantity; i++) {
		fin >> key[i] >> parent[i] >> LR[i];
		if (key[i] < interval[parent[i]].first || key[i] >= interval[parent[i]].second) {
			fout << "NO";
			return 0;
		}
		if (LR[i] == "L" && key[i] >= key[parent[i]]) {
			fout << "NO";
			return 0;
		}
		if (LR[i] == "R" && key[i] < key[parent[i]]) {
			fout << "NO";
			return 0;
		}
		if (LR[i] == "L") {
			interval[i].first = interval[parent[i]].first;
			interval[i].second = key[parent[i]];
		}
		else if (LR[i] == "R") {
			interval[i].first = key[parent[i]];
			interval[i].second = interval[parent[i]].second;
		}
	}
	fout << "YES";
	fin.close();
	fout.close();
}
