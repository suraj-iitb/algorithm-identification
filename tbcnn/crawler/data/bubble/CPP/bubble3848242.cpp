#include <iostream> //! 使用 flag 的冒泡排序

using namespace std;

const int N = 1e2 + 10;

int n, a[N];

int bubble_sort(int a[], int n)
{
    int sw = 0;
    bool flag = true;

    for(int i = 0; flag; i++)
    {
        flag = false;
        for(int j = n - 1; j >= i + 1; j--)
        {
            if(a[j] < a[j - 1]) //! 换了就证明前面不是有序的
            {
                swap(a[j], a[j - 1]);
                flag = true;
                sw++;
            }
        }
    }

    return sw;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    int sw = bubble_sort(a, n);

    for(int i = 0; i < n; i++)
    {
        if(i > 0) cout << ' ';
        cout << a[i];
    }

    cout << endl;

    cout << sw << endl;

    return 0;
}
