#include <iostream>
#include <vector>

template<class T> void output(std::vector<T> & A) {
    const int n = A.size();
    for (int i = 0; i < n - 1; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << A[n - 1] << std::endl;
}

void swapval(int& a, int& b) {
    const int tmp = a;
    a = b;
    b = tmp;
}

void selectionSort(std::vector<int>& A) {
    const int N = A.size();
    int cnt = 0;
    for (int i = 0; i < N - 1; ++i) {
        int minj = i;
        for (int j = i; j < N; ++j) {
            if (A[minj] > A[j]) {
                minj = j;
            }
        }
        if (i != minj) {
            swapval(A[minj], A[i]);
            ++cnt;
        }
    }
    output(A);
    std::cout << cnt << std::endl;
}

int main() {
    int n; std::cin >> n;
    std::vector<int> A(n);
    for (int i = 0; i < n; ++i) std::cin >> A[i];

    selectionSort(A);

    return 0;
}
