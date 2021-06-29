#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <utility>
using namespace std;

void trace(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << a[i] << " ";
    cout << a[n - 1] << "\n";
}

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void SelectionSort(int a[], int n)
{
    bool flag = true;
    int count = 0;
    int minj;
    for (int i = 0; i < n; i++)
    {
        minj = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[minj])
                minj = j;
        }
        if (i != minj)
        {
            swap(&a[i], &a[minj]);
            count++;
        }
    }
    trace(a, n);
    cout << count << "\n";
}

int main(void)
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    SelectionSort(a, n);

    return 0;
}

