#include<iostream>
static const int NMAX = 100;

void PrintArray(const int* A, int N);
int BubbleSort(int* A, int N);

int main() {
    int A[NMAX], n, swapNr;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    swapNr = BubbleSort(A, n);
    PrintArray(A, n);

    std::cout << swapNr << std::endl;

    return 0;
}

void PrintArray(const int* A, int N) {
    for (int i = 0; i < N; i++)
    {
        if (i > 0) {
            std::cout << " ";
        }
        std::cout << A[i];
    }
    std::cout << std::endl;
}

int BubbleSort(int* A, int N) {
    int swapNr;
    bool flag;

    swapNr = 0;
    flag = 1;

    int i = 0;
    while (flag) {
        flag = 0;
        for (int j = N - 1; j > i; j--) {
            if (A[j] < A[j - 1]) {
                int tmp;
                tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                flag = 1;
                swapNr++;
            }
        }
        i++;
    }
    return swapNr;
}
