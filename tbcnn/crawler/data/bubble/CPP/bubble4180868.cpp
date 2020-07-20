#include <bits/stdc++.h>

using namespace std;

int c = 0;
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                c++;
            }
        }
    }
}

int a[110];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    bubbleSort(a, n);
    for (int i = 0; i < n-1; i++)
    {
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
    cout << c << endl;

    return 0;
}
