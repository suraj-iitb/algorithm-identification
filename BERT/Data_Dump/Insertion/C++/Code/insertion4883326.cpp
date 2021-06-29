#include <iostream>
using namespace std;

void trace(int *a, int n) //输出每次排序结果
{
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            cout << " ";
        cout << a[i];
    }
    cout << endl;
}

void insertsort(int *a, int &n)
{
    int v, j = 0;
    for (int i = 0; i < n; i++)
    {
        v = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > v) //找到a[i]正确的位置
        {
            a[j + 1] = a[j]; //元素后移
            j--;             //继续向前
        }
        a[j + 1] = v;//当前元素移到正确位置
        trace(a, n); //输出
    }
}

int main()
{
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    insertsort(a, n); //进行插入排序
    return 0;
}
