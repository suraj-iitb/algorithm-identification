#include <iostream>
#include <string>

int main() {
    int n, count = 0;
    std::cin >> n;

    int A[n];
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    bool flag = true;
    while (flag) {
        flag = false;
        for (int j = n-1; j >= 0; j--) {
            if (A[j] < A[j-1]) {
                std::swap(A[j], A[j-1]);
                flag = true;
                count++;
            }
        }
    }

    for (int k = 0; k < (n-1); k++) std::cout << A[k] << " ";
    std::cout << A[n-1] << std::endl;
    std::cout << count << std::endl;

    return 0;
    
}
