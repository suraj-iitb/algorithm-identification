#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[101];
    int N = 0, v = 0, j, num = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        cout << a[i];
        if (i < N) cout << " ";
        else cout << '\n';
    }
    //排序算法
    for (int i = 2; i <= N; i++)
    {
        v = a[i];
        j = i - 1;
        while (j >= 1 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        for (int k = 1; k <= N; k++)
        {
            cout << a[k];
            num++;
            if (num % N != 0) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
