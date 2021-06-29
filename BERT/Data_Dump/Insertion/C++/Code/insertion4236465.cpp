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
    printAll(A);

    int v, j;
    for (int i = 1; i < N; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 & A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        printAll(A);
    }

}
