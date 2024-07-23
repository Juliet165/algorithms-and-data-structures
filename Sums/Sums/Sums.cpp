#include <iostream>
#include <vector>
#include <cmath>
#include <string>

long long findSum(int l, int r, const std::vector<long long>& arr, const std::vector<long long>& b) {
    long long k = sqrt(arr.size());
    long long jl = l / k;
    long long jr = r / k;
    long long sum = 0;

    if (jl == jr) {
        for (int i = l; i < r; i++) {
            sum += arr[i];
        }
        return sum;
    }
    else {
        for (int i = l; i < (jl + 1) * k; i++) {
            sum += arr[i];
        }
        for (int i = jl + 1; i < jr; i++) {
            sum += b[i];
        }
        for (int i = jr * k; i < r; i++) {
            sum += arr[i];
        }
        return sum;
    }
}

void Add(long long i, long long x, std::vector<long long>& arr, std::vector<long long>& b) {
    arr[i] += x;
    int k = sqrt(arr.size());
    b[i / k] += x;
}

int main() {
    long long n;
    std::cin >> n;
    std::vector<long long> arr(n);

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    long long sq = sqrt(n);
    std::vector<long long> sums((n + sq - 1) / sq);

    for (int i = 0; i < sums.size(); i++) {
        long long bsum = 0;
        for (int j = i * sq; j < (i + 1) * sq && j < n; j++) {
            bsum += arr[j];
        }
        sums[i] = bsum;
    }

    long long q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        std::string name;
        std::cin >> name;
        if (name == "Add") {
            long long i, x;
            std::cin >> i >> x;
            Add(i, x, arr, sums);
        }
        else if (name == "FindSum") {
            long long l, r;
            std::cin >> l >> r;
            std::cout << findSum(l, r, arr, sums) << "\n";
        }
    }

}
