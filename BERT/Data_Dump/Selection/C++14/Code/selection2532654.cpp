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
    for (int i = 0; i < n; i++)
    {
        int mini = i;
        for (int j = i + 1; j < n; j++)
        {
            if(a[mini] > a[j])
            {
                mini = j;
            }
        }
        if(i != mini)
        {
            swap(a[mini], a[i]);
            s++;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", a[i]);
    }
    printf("%d\n%d\n", a[n - 1], s);
}
