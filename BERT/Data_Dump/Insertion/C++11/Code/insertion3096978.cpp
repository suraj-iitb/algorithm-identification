#include <iostream>
#include <vector>

void output(std::vector<int> vec) {
    for (int i = 0; i < vec.size(); i ++) {
        if (i > 0) std::cout << " ";
        std::cout << vec[i];
    }
    std::cout << std::endl;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i ++) {
        std::cin >> A[i];
    }

    output(A);
    for (int i = 1; i < N; i ++) {
        int v = A[i];
        int j;
        for (j = i - 1; j >= 0; j --) {
            if (A[j] <= v) break;
            A[j+1] = A[j];
        }
        A[j+1] = v;

        output(A);
    }
}

