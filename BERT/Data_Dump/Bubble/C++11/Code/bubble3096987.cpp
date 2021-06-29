#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i ++) {
        std::cin >> A[i];
    }

    int n_swaps = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int j = N - 1; j >= 1; j --) {
            if (A[j] < A[j-1]) {
                std::swap(A[j], A[j-1]);
                flag = true;
                n_swaps += 1;
            }
        }
    }

    for (int i = 0; i < N; i ++) {
        if (i > 0) std::cout << " ";
        std::cout << A[i];
    }
    std::cout << std::endl;
    std::cout << n_swaps << std::endl;
}

