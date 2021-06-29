#include<iostream>
#include<algorithm>
using namespace std;
int a[500005];int ans=0;
int L[500005/2+2],R[500005/2+2];
const int INF=1e9;
void Merge(int a[],int l,int m,int r)
{
    int n1=m-l;
    int n2=r-m;
    for(int i=0;i<n1;i++)L[i]=a[l+i];
    for(int i=0;i<n2;i++)R[i]=a[m+i];
    L[n1]=R[n2]=INF;
    int i=0,j=0;
    for(int k=l;k<r;k++)
    if(L[i]<R[j])
    {
        a[k]=L[i++];
        ans++;
    }
    else
    {
        a[k]=R[j++];
        ans++;
    }
}
void mergeSort(int a[],int l,int r)
{
    if(l+1<r)
    {
        int m=l+r>>1;
        mergeSort(a,l,m);
        mergeSort(a,m,r);
        Merge(a,l,m,r);
    }
}
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)cin>>a[i];
        mergeSort(a,0,n);
        for(int i=0;i<n;i++)
        {
            if(i)cout<<' ';
            cout<<a[i];
        }
        cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}

