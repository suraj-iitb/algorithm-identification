#include<stdio.h>
int bubbleSort(int a[],int n)
{
    int tmp,j,flag=1;
    int count=0;
    while(flag)
    {
        flag=0;
        for(j=n-1;j>0;j--)
        {
            if(a[j]<a[j-1])
            {
                tmp=a[j-1];
                a[j-1]=a[j];
                a[j]=tmp;
                flag=1;
                count++;
            }
        }
    }
    return count;
}

int main(void)
{
    int a[100],n,i,count;
    
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    count=bubbleSort(a,n);
    
    for(i=0;i<n;i++)
    {
        if(i>0){printf(" ");}
        printf("%d",a[i]);
    }
    printf("\n");
    printf("%d\n",count);
    return 0;
}
