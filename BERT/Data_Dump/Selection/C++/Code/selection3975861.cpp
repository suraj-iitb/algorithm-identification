#include <iostream>
#include <cstdio>
using namespace std;

void SelectionSort(int A[], int N);
static int cnt = 0;

int main(void)
{
    int N, A[100];

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    SelectionSort(A, N);
    for(int i = 0; i < N; i++)
    {
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl << cnt << endl;

    return 0;
}

void SelectionSort(int A[], int N)
{
    for(int i = 0; i < N - 1; i++)
    {
        int minj = i;
        for(int j = i; j < N; j++)
        {
            if(A[j] < A[minj])
            {
                minj = j;
            }
        }
        if(i != minj)
        {
            swap(A[i], A[minj]);
            cnt++;
        }
        
    }
}
