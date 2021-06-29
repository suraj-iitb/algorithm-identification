#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) FOR(i, 0, n)

using namespace std;

void insertionSort(int a[], int n)
{
    rep(j, n)
        {
            if (j > 0)
                printf(" ");
            printf("%d", a[j]);
        }
        printf("\n");
    FOR(i, 1, n)
    {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;

        rep(j, n)
        {
            if (j > 0)
                printf(" ");
            printf("%d", a[j]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];

    insertionSort(a, n);
}
