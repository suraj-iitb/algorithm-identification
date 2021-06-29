//https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_A

#include <iostream>
#include <vector>

using namespace std;

void insertSort(vector<int> A, int N)
{
    int v, j;
    for (int i = 0; i < N; i++)
    {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;

        for (int i = 0; i < N; i++)
        {
            if (i < N - 1)
                std::cout << A[i] << " ";
            else
                std ::cout << A[i] << std::endl;
        }
    }
}

int main()
{
    int N;
    std::cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        std::cin >> A[i];

    insertSort(A, N);

    return 0;
}

