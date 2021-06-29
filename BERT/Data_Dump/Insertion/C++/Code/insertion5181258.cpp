#include <iostream>
#include <algorithm>

static const int MAX = 1000;

void print_series(int A[MAX], int N)
{
    for (int k = 0; k < N; k++)
    {
        if (k > 0)
        {
            std::cout << " ";
        }
        std::cout << A[k];
    }
    std::cout << std::endl;
}

int main()
{
    int N, v, A[MAX], j;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> A[i];
    }

    print_series(A, N);
    for (int i = 1; i < N; i++)
    {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        print_series(A, N);
    }

    return 0;
}
