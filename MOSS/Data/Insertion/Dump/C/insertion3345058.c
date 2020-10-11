#include<stdio.h>
void out(int a[],int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        if(i>0) printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
}
void sort(int a[],int N)
{
    int i,j,temp;
    for(i=1;i<N;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0&&a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
        out(a,N);
    }
}
int main()
{
    int t,N,a[100];
    scanf("%d",&N);
    for(t=0;t<N;t++)
    {
        scanf("%d",&a[t]);
    }
    out(a,N);
    sort(a,N);
}

