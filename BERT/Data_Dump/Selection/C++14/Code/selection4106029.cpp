#include<iostream>
static const int NMAX = 100;

void PrintArray(const int* A, int N);
int SelectionSort(int* A, int N);

int main() {
    int A[NMAX], n, swapNr;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    swapNr = SelectionSort(A, n);
    PrintArray(A, n);
    std::cout << swapNr << std::endl;

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

int SelectionSort(int* A, int N) {
    int swapNr = 0, minIndex;

    for (int i = 0; i < N - 1; i++) {
        minIndex = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int tmp;
            tmp = A[i];
            A[i] = A[minIndex];
            A[minIndex] = tmp;

            swapNr++;
        }
    }

    return swapNr;
}
