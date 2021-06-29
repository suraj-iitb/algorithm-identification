#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, tedad = 0, mini;
    cin >> n;
    int adad[n];
    for (int i = 0; i < n; i++)
    {
        cin >> adad[i];
    }
    for (int i = 0; i < n; i++)
    {
        mini = i;
        for (int j = i; j < n; j++)
        {
            if (adad[j] < adad[mini])
            {
                mini = j;
            }
        }
        if (adad[i] != adad[mini])
        {
            tedad++;
        }
        swap(adad[i], adad[mini]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << adad[i] << " ";
    }
    cout << adad[n - 1] << endl
         << tedad<<endl;
}
