#include <bits/stdc++.h>

void printAll(std::vector<int> A) {
    for (int i = 0; i < (A.size()-1); i++) {
        std::cout << A[i] << " ";
    }
    std::cout << A.back() << std::endl;
}

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int count = 0;
    for (int i = 0; i < A.size(); i++) {
        for (int j = A.size() - 1; j > i; j--) {
            if (A[j] < A[j-1]) {
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                count++;
            }
        }
    }

    printAll(A);
    std::cout << count << std::endl;
}
