#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++)
    {
        int b = a[i], j;
        for (int i = 0; i < n - 1; i++)
        {
            printf("%d ", a[i]);
        }
        printf("%d\n", a[n - 1]);
        for (j = i - 1; j >= 0 && a[j] > b; j--)
        {
            a[j + 1] = a[j];
            
        }
        a[j + 1] = b;
    }
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n - 1]);
}
