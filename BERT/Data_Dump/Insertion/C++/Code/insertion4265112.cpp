#include <iostream>
#include <stdio.h>
using namespace std;

void print(int A[],int n) {
    for (int i = 0; i < n; i++)
        printf("%d%c", A[i], i == n - 1 ? '\n' : ' ');
}

void insertionSort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && v < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;

        print(a,n);
    }
}
int main()
{
    int n = 0, a[105];
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    print(a,n);
    insertionSort(a, n);
    return 0;
}
