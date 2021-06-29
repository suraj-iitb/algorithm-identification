#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF=10000000;
const int mod=1e9+7;
int a[100005];
int n,ant;
void ss()
{
    int mn;
    for(int i=0;i<n-1;i++)
    {
        mn=i;
        for(int j=i;j<n;j++)
        {
            if(a[j]<a[mn])
                mn=j;
        }
        swap(a[i],a[mn]);
        if(i!=mn)
            ant++;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    ss();
    for(int i=0;i<n;i++)
    {
        if(i)
            printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
    printf("%d\n",ant);
    return 0;
}

