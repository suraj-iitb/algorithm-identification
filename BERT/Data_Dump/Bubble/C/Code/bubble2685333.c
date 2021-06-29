#include<stdio.h>
#include<string.h>
void show(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(i) putchar(' ');
        printf("%d",a[i]);
    }
}
void bubble(int a[],int n)
{
    int flag=1,i,j,count=0;
    for(i=0;flag;i++)
    {
        flag=0;
        for(j=n-1;j>=i+1;j--)
        {
            if(a[j-1]>a[j])
            {
                flag=1;
                a[j]^=a[j-1];
                a[j-1]^=a[j];
                a[j]^=a[j-1];
                count++;
            }
        }
    }
    show(a,n);
    putchar('\n');
    printf("%d\n",count);
}

int main()
{
    int a[101];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    bubble(a,n);
}

