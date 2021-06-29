/*
 * Problem: Prime Numbers
 * Author: Khan
 * Date: 11th October, 2017
 */
#include <iostream>

using namespace std;

int selectionSort(int A[], int N)
{
    int i, j, t, sw = 0, minj;
    for (i = 0; i < N - 1; ++i)
    {
        minj = i;
        for (j = i; j < N; ++j)
        {
            if(A[minj] > A[j])
                minj = j;
        }
        swap(A[i], A[minj]);
        if(i != minj)
            sw++;
    }
    return sw;
}

int main(int argc, char const *argv[])
{
    int A[100], N, sw;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    sw = selectionSort(A, N);

    for (int i = 0; i < N; ++i)
    {
        if(i)
            cout << " ";
        cout << A[i];
    }

    cout << endl;
    cout << sw << endl;
    return 0;
}
