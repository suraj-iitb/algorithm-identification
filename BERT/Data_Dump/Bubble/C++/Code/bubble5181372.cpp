#include <iostream>

static const int MAX = 100;

int bubbleSort(int A[MAX], int N)
{
    int sorted = 0;
    int count = 0;
    int flag = 1;

    while (flag)
    {
        flag = 0;
        for (int j = N - 1; j > sorted; j--)
        {
            if (A[j] < A[j - 1])
            {
                std::swap(A[j], A[j - 1]);
                flag = 1;
                count++;
            }
        }
        sorted++;
    }
    return count;
}

int main()
{
    int N;
    std::cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
    {
        std::cin >> A[i];
    }
    int count = bubbleSort(A, N);

    for (int i = 0; i < N; i++)
    {
        if (i > 0)
        {
            std::cout << " ";
        }
        std::cout << A[i];
    }
    std::cout << std::endl
              << count << std::endl;
    return 0;
}
