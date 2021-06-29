#include <iostream>
using namespace std;
int main()
{
    int n, a[100],x=0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        for (int t = 0; t < n - 1; t++)
        {
            if (a[t + 1] < a[t])
            {
                swap(a[t], a[t + 1]);
                x++;
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << (i < n - 1 ? " " : "\n");
    
    cout << x << "\n";
}

