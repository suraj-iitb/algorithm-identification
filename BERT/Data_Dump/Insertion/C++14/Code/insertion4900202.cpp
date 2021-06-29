#include <bits/stdc++.h>
using namespace std;

void Cout_ALL(vector<long long> A, long long N);
void insertionSort(vector<long long> A, long long N);

//メイン
int main()
{
    long long N;
    vector<long long> A;

    cin >> N;
    A.resize(N);
    for (auto &x : A)
        cin >> x;

    insertionSort(A, N);

    return 0;
}

//出力
void Cout_ALL(vector<long long> A, long long N)
{
    for (int i = 0; i < N; i++)
    {
        cout << (i ? " " : "") << A[i];
    }
    cout << endl;
}

//並び替え
void insertionSort(vector<long long> A, long long N)
{
    long long v, j;

    Cout_ALL(A, N);

    for (long long i = 1; i < N; i++)
    {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;

        Cout_ALL(A, N);
    }
}
