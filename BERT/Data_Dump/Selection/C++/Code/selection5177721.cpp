#include <iostream>

using namespace std;
int main(void)
{
    int n, a[105], count = 0;
    ;
    cin >> n;
    int i, j;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int min, t;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            t = a[min];
            a[min] = a[i];
            a[i] = t;
            count++;
        }
    }
    for (i = 0; i < n - 1; i++)
    {
        cout << a[i] << " ";
    }
    cout << a[i] << endl
         << count << endl;

    return 0;
}
