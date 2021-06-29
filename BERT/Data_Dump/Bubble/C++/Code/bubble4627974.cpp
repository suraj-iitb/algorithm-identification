#include <iostream>
using namespace std;

int bubblesort(int n, int a[])
{
    int cnt = 0;
    for (int i = 0;i < n;i++)
    {
        for (int j = n-1;j >= i+1;j--)
        {
            if (a[j] < a[j-1])
            {
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
                cnt++;
            }
        }
    }
    return cnt;
}

int main ()
{
    int n, cnt = 0;
    cin >> n;
    int a[n];
    for (int i = 0;i < n;i++) cin >> a[i];
    
    cnt = bubblesort (n, a);
    
    for (int i = 0;i < n;i++)
    {
        cout << a[i];
        if (i < n-1) cout << " ";
    }
    cout << endl << cnt << endl;
    return 0;
}
