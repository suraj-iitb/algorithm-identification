#include "bits/stdc++.h"
using namespace std;
int main()
{
    int n, s = 0;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d ", &a[i]);
    }
    scanf("%d", &a[n - 1]);
    bool b = true;
    while (b)
    {
        b = false;
        for (int i = n - 1; i > 0; i--)
        {
            if(a[i - 1] > a[i])
            {
                swap(a[i - 1], a[i]);
                b = true;
                s++;
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", a[i]);
    }
    printf("%d\n%d\n", a[n - 1], s);
}
