#include <iostream>
using namespace std;

int selectionsort(int *a, int n)
{
    int sw = 0, minj;
    for (int i = 0; i < n - 1; i++)
    {
        minj = i;                   //初始i为当前最小位置
        for (int j = i; j < n; j++) //寻找i之后最小值位置
        {
            if (a[j] < a[minj])
            {
                minj = j; //最小值位置记为minj
            }
        }
        if (i != minj) //若最小值位置改变则交换
        {
            sw++;
            swap(a[i], a[minj]);
        }
    }
    return sw;
}

int main()
{
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sw = selectionsort(a, n);
    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << " ";
        cout << a[i];
    }
    cout << endl
         << sw << endl;
    return 0;
}
