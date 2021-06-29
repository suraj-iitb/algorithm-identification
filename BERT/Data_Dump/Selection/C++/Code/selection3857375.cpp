#include <iostream>

using namespace std;

const int N = 1e2 + 10;

int n;
int a[N];

int selection_sort(int a[], int n)
{
    int i, j, t, sw = 0, minj;
    for(i = 0; i < n - 1; i++)
    {
        minj = i;
        for(int j = i; j < n; j++)
        {
            if(a[j] < a[minj]) minj = j;
        }
        swap(a[i], a[minj]);
        if(i != minj) sw++;
    }

    return sw;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    int sw =selection_sort(a, n);

    for(int i = 0; i < n; i++)
    {
        if(i > 0) cout << ' ';
        cout << a[i];
    }
    cout << endl;

    cout << sw << endl;

    return 0;
}
