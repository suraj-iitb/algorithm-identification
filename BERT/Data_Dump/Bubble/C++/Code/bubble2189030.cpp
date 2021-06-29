#include <iostream>
#include <cstdlib>
#include <vector>

int bubbleSort(std::vector<int> &A, int N); 

int main(void) {
    int N;
    std::cin >> N;
    std::vector<int> A(N, 0);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    int trade = bubbleSort(A, N);

    std::cout << A[0];
    for (int i = 1; i < N; i++) {
        std::cout << " " << A[i];
    } 
    std::cout << std::endl;

    std::cout << trade << std::endl;
    return EXIT_SUCCESS;
}

int bubbleSort(std::vector<int> &A, int N) {
    int trade = 0;
    bool flag = 1;
    int temp;
    while (flag) {
        flag = 0;
        for (int j = N - 1; j >= 1; j--) {
            if (A[j] < A[j - 1]) {
                temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
                flag = 1;
                trade++;
            }
        }
    }
    return trade;
}
