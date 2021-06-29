#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,mindata=100;
    int temp,j,cont=0;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++)
    {
        mindata=i; //i为此次需要插入的位置
        for(j=i+1;j<n;j++)   //找最小值，与数组每个数比较
            if(a[j]<a[mindata])
            mindata=j;
        if(mindata!=i)  //如果i的位置的数不是最小的数就交换
        {
            temp=a[i];
            a[i]=a[mindata];
            a[mindata]=temp;
            cont++;
        }
    }
      for(int i=0;i<n;i++)
    {
        if(i>0)
            printf(" ",a[i]);

            printf("%d",a[i]);
    }
        printf("\n%d\n",cont);
    return 0;
}

