#include <iostream>
using namespace std;

void print(int n, int *a)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << ((i == n - 1) ? '\n' : ' ');
}

int main(int argc, char const *argv[])
{
    int n;
    int a[100];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    print(n, a);

    for (int i = 1; i < n; i++)
    {
        int v = a[i];
        int j;
        for (j = i - 1; j >= 0 && a[j] > v; j--)
            a[j + 1] = a[j];

        a[j + 1] = v;

        print(n, a);
    }
    return 0;
}

