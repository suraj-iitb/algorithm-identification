#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
void insertionSort(int a[],int n)
{
    for(int i = 0;i < n;i++)
    {
        cout << a[i];
        if(i != n - 1)
        {
            cout << " ";
        }
    }
    cout << "\n";
    for(int i = 1;i < n;i++)
    {
        int v = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        for(int k = 0;k < n;k++)
        {
            cout << a[k];
            if(k != n - 1)
            {
                cout << " ";
            }
        }
        cout << "\n";
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    insertionSort(a,n);

    return 0;
}
