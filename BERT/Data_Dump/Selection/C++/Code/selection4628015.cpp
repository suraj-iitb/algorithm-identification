#include <iostream>
using namespace std;

int selectionsort(int n, int a[])
{
    int cnt = 0;
    for (int i = 0;i < n;i++)
    {
        int mini = i;
        for (int j = i;j < n;j++)
        {
            if (a[j] < a[mini])
            {
                mini = j;
            }
        }
        if (mini != i)
        {
            int temp = a[i];
            a[i] = a[mini];
            a[mini] = temp;
            cnt++;
        }
    }
    return cnt;
}

int main ()
{
    int n, cnt;
    cin >> n;
    int a[n];
    for (int i = 0;i < n;i++) cin >> a[i];
    
    cnt = selectionsort(n, a);
    
    for (int i = 0;i < n;i++)
    {
        cout << a[i];
        if (i < n-1) cout << " ";
    }
    cout << endl << cnt << endl;
    return 0;
}
