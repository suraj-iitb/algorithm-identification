/*
   ?????\??????????????¢?????´?????????

   1 insertionSort(A, N) // N??????????´??????????0-?????????????????????A
   2   for i ??? 1 ?????? N-1 ?????§
   3     v = A[i]
   4     j = i - 1
   5     while j >= 0 ?????? A[j] > v
   6       A[j+1] = A[j]
   7       j--
   8     A[j+1] = v
 */

#include <iostream>
#include <cstdlib>
#include <vector>

void insertionSort(std::vector<int> A, int N);
void print(std::vector<int> A, int N);

int main(void) {
    int N;
    std::cin >> N;
    std::vector<int> A(N, 0);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    insertionSort(A, N);

    return EXIT_SUCCESS;
}

void insertionSort(std::vector<int> A, int N) {
    int v;
    int j;
    print(A, N);
    for (int i = 1; i <= N - 1; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
            A[j + 1] = v;
        }
        print(A, N);
    }
}

void print(std::vector<int> A, int N) {
    for (int i = 0; i < N - 1; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << A[N - 1] << std::endl;
}
