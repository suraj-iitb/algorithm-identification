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

int main(void)
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int v, i, j;
    for (i = 1; i < n; i++)
    {

        for (j = 0; j < n - 1; j++)
            cout << a[j] << " ";
        cout << a[n - 1] << "\n";

        v = a[i];
        for (j = i - 1; j >= 0 && a[j] > v; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = v;
    }

    for (j = 0; j < n - 1; j++)
        cout << a[j] << " ";
    cout << a[n - 1] << "\n";

    return 0;
}

