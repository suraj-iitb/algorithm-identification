#include <iostream>

const int MAX = 100;

int BubbleSort(int *A, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = n-1; j > 0; --j)
            if (A[j] < A[j-1]) {
                int save = A[j];
                A[j] = A[j-1];
                A[j-1] = save;
                ++cnt;
            }
    return cnt;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int A[MAX];
    int N, cnt;
    std::cin >> N;
    for (int i = 0; i < N; ++i)
        std::cin >> A[i];
    cnt = BubbleSort(A, N);
    for (int i = 0; i < N; ++i) {
        std::cout << A[i];
        if (i < N-1) std::cout << " ";
        else std::cout << std::endl;
    }
    std::cout << cnt << std::endl;

    return 0;
}

