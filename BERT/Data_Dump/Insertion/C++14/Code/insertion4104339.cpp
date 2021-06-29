#include<iostream>
static const int NMAX = 100;

void PrintArray(const int* A, int N);
void InsertionSort(int* A, int N);

int main() {
    int A[NMAX], n;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    PrintArray(A, n);
    InsertionSort(A, n);

    return 0;
}

void PrintArray(const int* A, int N) {
    for (int i = 0; i < N; i++) {
        if (i > 0) {
            std::cout << " ";
        }
        std::cout << A[i];
    }
    std::cout << std::endl;
}

void InsertionSort(int* A, int N) {
    for (int i = 1; i < N; i++) {
        int tmp = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > tmp) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = tmp;

        PrintArray(A, N);
    }
}
