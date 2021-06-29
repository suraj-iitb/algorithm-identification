#include <bits/stdc++.h>

using namespace std;

// void insertion(int a[], int n)
// {
//     for (int i = 1; i < n; i++)
//     {
//         int v = a[i];
//         int j = i - 1;
//         while (j >= 0 && a[j] > v)
//         {
//             a[j + 1] = a[j];
//             j--;
//         }
//         a[j + 1] = v;
//     }
// }
int a[1010];
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << " ";
    }
    cout << a[n - 1];
    cout << endl;
    for (int i = 1; i < n; i++)
    {

        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        for (int j = 0; j < n - 1; j++)
        {
            cout << a[j] << " ";
        }
        cout << a[n - 1];
        cout << endl;
    }

    return 0;
}
