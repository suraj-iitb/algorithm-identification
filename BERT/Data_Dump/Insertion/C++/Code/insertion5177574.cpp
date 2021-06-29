#include <iostream>

using namespace std;
int main(void)
{
    int n;
    int a[200];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int j, k;
    for (int i = 1; i < n; i++)
    {
        for (k = 0; k < n - 1; k++)
        {
            cout << a[k] << " ";
        }
        cout << a[k] << endl;

        int b = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > b)

        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = b;
    }
    for (k = 0; k < n - 1; k++)
    {
        cout << a[k] << " ";
    }
    cout << a[k] << endl;

    return 0;
}
