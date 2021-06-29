#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=500000;
const int INF=2e9;
int L[maxn/2+2],R[maxn/2+2];
int cnt;
void merge_sort(int a[],int n,int l,int mid,int r)
{
    int n1=mid-l;
    int n2=r-mid;
    for(int i=0;i<n1;i++)
    {
        L[i]=a[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        R[i]=a[mid+i];
    }
    L[n1]=R[n2]=INF;
    int p=0,q=0;
    for(int i=l;i<r;i++)
    {
        cnt++;
        if(L[p]<=R[q])
            a[i]=L[p++];
        else
            a[i]=R[q++];
    }
}
void get_merge(int a[],int n,int l,int r)
{
    if(l+1<r)
    {
        int mid=(l+r)/2;
        get_merge(a,n,l,mid);
        get_merge(a,n,mid,r);
        merge_sort(a,n,l,mid,r);
    }
}
int main()
{
    int a[maxn],n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    get_merge(a,n,0,n);
    for(int i=0;i<n;i++)
    {
        if(i)
            printf(" ");
        printf("%d",a[i]);
    }
    printf("\n%d\n",cnt);
    return 0;
}

