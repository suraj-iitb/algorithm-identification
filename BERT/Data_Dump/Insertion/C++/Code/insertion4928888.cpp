#include <bits/stdc++.h>
using namespace std;
void print_arr(int adad[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        cout << adad[i] << " ";
    }
    cout << adad[n - 1] << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, key, j;
    cin >> n;
    int adad[n];
    for (int i = 0; i < n; i++)
    {
        cin >> adad[i];
    }
    print_arr(adad, n);
    for (int i = 1; i < n; i++)
    {
        key = adad[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (adad[j] > key)
            {
                adad[j + 1] = adad[j];
            }
            else
            {
                break;
            }
        }
        adad[j + 1] = key;
        print_arr(adad, n);
    }
}
