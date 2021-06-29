#include <stdio.h>

void Trace(int n, int *a)
{
    for(int i=0; i<n; i++)
    {
        if(i!=n-1)
            printf("%d ", a[i]);
        else
            printf("%d\n", a[i]);
    }
}

void BubbleSort(int n, int *a)
{
    int i, j, v;
    int count = 0;
    int flag = 1;
    for(i=0; flag; i++)
    {
        flag = 0;
        for(j=0; j<n-i-1; j++)
        {
            if(a[j]>a[j+1])
            {//注意这里如果将>改为>=，则算法会失去稳定性（即相同元素排序后的顺序不是排序前的顺序）
                v = a[j];
                a[j] = a[j+1];
                a[j+1] = v;
                count++;
                flag = 1;
            }
        }
    }
    Trace(n, a);
    printf("%d\n", count);
}

int main(void)
{
    int i, n;
    scanf("%d", &n);
    int a[n];
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    BubbleSort(n, a);
    return 0;
}
