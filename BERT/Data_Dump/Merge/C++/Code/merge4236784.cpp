#include <bits/stdc++.h>
using namespace std;

int merge(int a[], int n)
{
    int l[n / 2 + 1];
    int r[n - n / 2 + 1];

    for (int i = 0; i < n / 2; i++)
        l[i] = a[i];
    l[n / 2] = 1145141919;
    for (int i = 0; i < n - n / 2; i++)
        r[i] = a[n / 2 + i];
    r[n - n / 2] = 1145141919;

    int i = 0, j = 0;
    for (int k = 0; k < n; k++)
    {
        if (l[i] <= r[j])
        {
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
        }
    }

    return n;
}

int mergeSort(int a[], int n)
{
    int cnt = 0;
    if (n > 1)
    {
        cnt += mergeSort(a, n / 2);
        cnt += mergeSort(a + n / 2, n - n / 2);
        cnt += merge(a, n);
    }
    return cnt;
}

int main(void)
{
    int n;
    cin >> n;
    int s[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    int cnt = mergeSort(s, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d", s[i]);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n");
    printf("%d\n", cnt);
}
