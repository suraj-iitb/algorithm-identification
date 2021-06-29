#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n, cnt = 0;
    bool flag = true;
    scanf("%d", &n);
    int *a = new int[n];
    for(int i = 0;i < n;++i){scanf("%d", &a[i]);}
    for(int i = 0;flag;++i)
    {
        flag = false;
        for(int j = 0;j < n - i - 1;++j)
        {
            if(a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
                flag = true;
                ++cnt;
            }
        }
    }
    for(int i = 0;i < n-1;++i){printf("%d ", a[i]);}
    printf("%d\n", a[n-1]);
    printf("%d\n", cnt);
    return 0;
}
