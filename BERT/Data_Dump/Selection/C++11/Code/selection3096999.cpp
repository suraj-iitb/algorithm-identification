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
    for (int i = 0; i < N; i ++) {
        int minj = i;
        for (int j = i; j < N; j ++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (A[i] != A[minj]) {
            std::swap(A[i], A[minj]);
            n_swaps += 1;
        }
    }

    for (int i = 0; i < N; i ++) {
        if (i > 0) std::cout << " ";
        std::cout << A[i];
    }
    std::cout << std::endl;
    std::cout << n_swaps << std::endl;
}

