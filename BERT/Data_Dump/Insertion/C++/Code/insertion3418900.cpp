#include <iostream>
#include <stdio.h>
using namespace std;

int n, A[100];

void ShowArray(int *arr)
{
    for (int i = 0; i < n; i++)
    {
        if (i != n-1) printf("%d ", arr[i]);
        else printf("%d\n", arr[i]);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    ShowArray(A);
    for (int i = 1; i < n; i++) 
    {
        int target = A[i];
        int j = i-1;
        while (j >= 0 && A[j] > target)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = target;
        ShowArray(A);
    }

    return 0;
}
