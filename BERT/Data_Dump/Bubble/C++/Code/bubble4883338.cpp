#include <iostream>
using namespace std;

int bubblesort(int *a, int n) //flag优化的冒泡算法
{
    int t = 0;
    bool flag = 1;
    for (int i = 0; flag; i++) //若flag为0则说明上次没有交换，则数组已经有序停止循环
    {
        flag = 0;
        for (int j = n - 1; j >= i + 1; j--) //从后向前对中间部分进行比较
        {
            if (a[j] < a[j - 1]) //对相邻两元素进行比较
            {
                swap(a[j], a[j - 1]); //交换两元素
                t++;
                flag = 1; //flag=1表示本轮已进行交换
            }
        }
    }
    return t;
}

int main()
{
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int t = bubblesort(a, n);
    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << " ";
        cout << a[i];
    }
    cout << endl
         << t << endl;
    return 0;
}
