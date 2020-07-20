#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF=10000000;
const int mod=1e9+7;
int a[100005];
int n,ant;
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
void bubble()
{
    bool flag=1;
    for(int i=0;flag;i++)
    {
        flag=0;;
        for(int j=n-1;j>=i;j--)
        {
            if(a[j]<a[j-1])
            {
                swap(a[j],a[j-1]);
                flag=1;
                ant++;
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    bubble();
    trace();
    printf("%d\n",ant);
    return 0;
}

