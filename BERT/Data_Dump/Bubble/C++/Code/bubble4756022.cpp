#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int temp = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j > i; j--)
        {
            if (a[j] < a[j - 1])
            {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                cnt++;
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        cout << a[k];
        if (k == n - 1)
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }
    cout << cnt << endl;
    return 0;
}
