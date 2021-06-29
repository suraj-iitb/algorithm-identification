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

void bubbleSort(int a[], int n)
{
    //trace(a, n);
    bool flag = true;
    int count = 0;
    while (flag)
    {
        flag = false;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] < a[i - 1])
            {
                flag = true;
                swap(&a[i], &a[i - 1]);
                count++;
            }
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

    bubbleSort(a, n);
    

    return 0;
}

