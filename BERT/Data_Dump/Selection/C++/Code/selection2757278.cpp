#include <iostream>

const int MAX = 100;

int SelectionSort(int *A, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int min = i;
        for (int j = i; j < n; ++j) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        int save = A[i];
        A[i] = A[min];
        A[min] = save;
        if (i != min) ++cnt;
    }

    return cnt;
}

int main()
{
    int A[MAX];
    int N, cnt;
    std::cin >> N;
    for (int i = 0; i < N; ++i)
        std::cin >> A[i];
    cnt = SelectionSort(A, N);
    for (int i = 0; i < N; ++i) {
        std::cout << A[i];
        if (i != N-1) std::cout << " ";
        else std::cout << std::endl;
    }
    std::cout << cnt << std::endl;

    return 0;
}

