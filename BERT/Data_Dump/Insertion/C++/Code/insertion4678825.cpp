#include <iostream>
#include <vector>

void swapval(int& a, int& b) {
    const int tmp = a;
    a = b;
    b = tmp;
    return;
}

void output(std::vector<int> & A) {
    const int n = A.size();
    for (int i = 0; i < n - 1; ++i) {
        std::cout << A[i] << " ";
     }
    std::cout << A[n - 1] << std::endl;
}

int main() {
    int N; std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) std::cin >> A[i];
    output(A);

    for (int i = 1; i < N; ++i) {
        int j = i - 1;
        for (int j = i - 1; j >= 0; --j) {
            if (A[j+1] > A[j]) break;
            swapval(A[j + 1], A[j]);
        }
        output(A);
    }

    return 0;

}
