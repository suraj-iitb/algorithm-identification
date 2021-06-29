#include <bits/stdc++.h>
using namespace std;

#define MAX 10001

void countingSort(int a[], int n)
{
    int c[MAX];
    for (int i = 0; i < MAX; i++)
        c[i] = 0;

    for (int i = 0; i < n; i++)
        c[a[i]]++;

    for (int i = 1; i < MAX; i++)
        c[i] = c[i] + c[i - 1];

    int b[n];
    for (int i = n - 1; i >= 0; i--)
    {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = b[i];
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    countingSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if (i != n - 1)
            cout << ' ';
    }
    cout << endl;
}
