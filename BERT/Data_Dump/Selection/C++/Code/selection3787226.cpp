#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

void cin_row(int* A, int N)
{
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
}

void cout_row(int* A, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (i != 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

int main()
{
#ifdef LOCAL
    // 以降 cin の入力元が 'xxx.txt' になる
    std::ifstream in("in.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int N = 0;

    cin >> N;

    int A[100];
    cin_row(A, N);

    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        int mini = i;
        for (int j = i; j < N; j++)
        {
            if (A[j] < A[mini]) mini = j;
        }
        if (i != mini)
        {
            std::swap(A[i], A[mini]);
            cnt++;
        }
    }



    cout_row(A, N);
    cout << cnt << endl;

    return 0;
}

