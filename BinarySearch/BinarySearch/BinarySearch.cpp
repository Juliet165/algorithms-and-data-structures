#include <iostream>
#include <vector>


int binarySearchLower(std::vector <int>& arr, int checkedNum) {
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

int binarySearchUpper(std::vector <int>& arr, int checkedNum) {
    int left = 0;
    int right = arr.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (checkedNum < arr[mid]) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

int binarySearch(std::vector <int>& arr, int checkedNum) {
  
    int left = 0;
    int right = arr.size();
    
    while (left < right) {
        int mid = (left + right) / 2;
        if (checkedNum == arr[mid]) {
            return 1;
        }
        else if (checkedNum < arr[mid]){
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return 0;
}

int main()
{
    int N;
    scanf_s("%d", &N);

    std::vector <int> myArray(N);
    for (int i = 0; i < N; i++) {
        scanf_s("%d", &myArray[i]);
    }

    int M;
    scanf_s("%d", &M);
    for (int i = 0; i < M; i++) {
        int finding = 0;
        scanf_s("%d", &finding);
        int l = binarySearchLower(myArray, finding);
        int b = binarySearch(myArray, finding);
        int r = binarySearchUpper(myArray, finding);
        /*std::printf("%d", b);
        std::printf("%d", l);
        std::printf("%d", r);*/
        std::cout << b << " " << l << " " << r;
        std::printf("\n");
    }
}