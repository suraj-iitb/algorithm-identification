#include <cstdio>

void print(int *a, int n)
{
    for(int i = 0;i < n - 1;++i){printf("%d ",a[i]);}
    printf("%d",a[n-1]);
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = new int[n];
    for(int i = 0;i < n;++i){scanf("%d", &a[i]);}
    for(int i = 1;i < n;++i)
    {
        print(a, n);
        int cur = a[i], j = i-1;
        while(j >= 0 && a[j] > cur){a[j+1] = a[j];j--;}
        a[j+1] = cur;
    }
    for(int i = 0;i < n-1;++i){printf("%d ",a[i]);}
    printf("%d\n",a[n-1]);
    return 0;
}
