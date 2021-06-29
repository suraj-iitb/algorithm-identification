#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n, cnt = 0;
    cin >> n;
    int *a = new int[n];
    for(int i = 0;i < n;++i){cin >> a[i];}
    for(int i = 0;i < n - 1;++i)
    {
        int minj = i;
        for(int j = i+1;j < n;++j)
        {
            if(a[j] < a[minj]){minj = j;}
        }
        if(minj != i){swap(a[i], a[minj]);cnt++;}
    }
    for(int i = 0;i < n-1;++i){cout << a[i] << ' ';}
    cout << a[n-1] << '\n' << cnt << '\n';
    return 0;
}
