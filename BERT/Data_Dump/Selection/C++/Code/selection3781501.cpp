//#include "bits/stdc++.h"
#include <iostream>
using namespace std;

void trace(int A[], int N)
{
    for (int i = 0; i < N; i++ )
    {
       if (i > 0)
           cout << " ";
       cout << A[i];
    }
    cout << "\n";
}

void insertionSort(int A[], int N)
{
    int j, i, v;
    for (i = 1; i < N; i++)
    {
        v = A[i];
        j = i - 1;
        while ( j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        trace(A, N);
    }
}

int bubbleSort(int A[], int N)
{
    int sw = 0;
    bool flag = 1;
    for (int i = 0; flag; i++)
    {
        flag = 0;
        for (int j = N - 1; j >= i + 1; j--)
        {
            if (A[j] < A[j - 1])
            {
                // 隣接要素を交換する
                swap(A[j], A[j - 1]);
                flag = 1;
                sw++;
            }
        }
    }
    return sw;
}

int selectionSort(int A[], int N)
{
    int t, sw = 0, minj;
    for (int i = 0; i < N - 1; i++)
    {
        minj = i;
        for (int j = i; j < N; j++)
        {
            if (A[j] < A[minj]) minj = j;
        }
        t = A[i];
        A[i] = A[minj];
        A[minj] = t;
        if (i != minj)
            sw++;
    }
    return sw;
}

int main()
{
    int A[1000], N, sw;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    sw = selectionSort(A, N);

        for (int i = 0; i < N; i++)
        {
            if (i) cout << " ";
            cout << A[i];
        }
    cout << endl;
    cout << sw << endl;

    return 0;
}
