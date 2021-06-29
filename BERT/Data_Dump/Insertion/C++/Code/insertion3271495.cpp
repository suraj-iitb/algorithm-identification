#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF=10000000;
const int mod=1e9+7;
int a[100005];
int n;
int extgcd(int a,int b,int& x,int& y)
{
    int d=a;
    if(b!=0)
    {
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
    return d;
}
void trace()
{
    for(int i=0;i<n;i++)
    {
        if(i)
            printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
}
void ins()
{
    int tmp,j;
    for(int i=1;i<n;i++)
    {
        tmp=a[i];
        j=i-1;
        while(j>=0&&a[j]>tmp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=tmp;
        trace();
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    trace();
    ins();
    return 0;
}

