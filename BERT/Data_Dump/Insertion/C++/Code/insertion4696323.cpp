#include <cstdio>
#include <iostream>

using namespace std;

const int max_n=100;

int a[max_n];

int main()
{
    int n;
    //  数据输入
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&a[i]);
    }
    // 插入排序
    int temp;
    // 输出初始数据
    int k;
    for(k=0;k<n-1;++k)
    {
        printf("%d ",a[k]);
    }
    printf("%d\n",a[k]);

    for(int i=1;i<n;++i)
    {
        temp=a[i];
        int j;
        // 此处的大于条件，可以保证算法是稳定的
        for(j=i-1;j>=0 && a[j]>temp;--j)
        {
            a[j+1]=a[j];
        }
        a[j+1]=temp;
        int k;
        // 输出中间过程
        for(k=0;k<n-1;++k)
        {
            printf("%d ",a[k]);
        }
        printf("%d\n",a[k]);
    }
    return 0;
}

