#include <iostream>

using namespace std;
int main(void)
{
    int n;
    int a[105];
    int count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int flag = 1;
    while (flag)
    {
        flag = 0;
        for (int i = n - 1; i > 0; i--)
        {
            if (a[i] < a[i - 1])
            {
                int t;
                t = a[i];
                a[i] = a[i - 1];
                a[i - 1] = t;
                flag = 1;
                count++;
            }
        }
    }
    int i;
    for (i = 0; i < n - 1; i++)
    {
        cout << a[i] << " ";
    }
    cout << a[i] << endl
         << count << endl;
    ;

    return 0;
}
