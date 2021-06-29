#include <iostream>
using namespace std;

int main()
{
    int n = 0, a[105];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

     int st = 0;
    for (int i = 0; i < n-1; i++)
    {
        int minj = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[minj])
            {
                minj = j;
            }
        }
        int temp = a[i];
        a[i] = a[minj];
        a[minj] = temp;

        if (i != minj) st++;
    }

    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << " ";
        cout << a[i];
    }
    cout<<endl;

    cout<<st<<endl;
    return 0;
}
