#include <cstdio>
#include <iostream>
using namespace std;
#define maxn 500005
#define sentinel 2000000000

int L[maxn/2+2],R[maxn/2+2];
long long cnt;

void _merge(int a[],int left,int mid,int right)
{
    int n1=mid-left;
    int n2=right-mid;
    for(int i=0;i<n1;++i)
        L[i]=a[left+i];
    for(int i=0;i<n2;++i)
        R[i]=a[mid+i];
    L[n1]=R[n2]=sentinel;
    int i=0,j=0;
    for(int k=left;k<right;++k)
    {
        cnt++;
        if(L[i]<=R[j])
        {
            a[k]=L[i++];
            //cout<<a[k]<<endl;
        }

        else
        {
            a[k]=R[j++];
            //cout<<a[k]<<endl;
        }

    }
}
void mergesort(int a[],int n,int left,int right)
{
    if(left+1<right)
    {
        int mid=(left+right)>>1;
        mergesort(a,n,left,mid);
        mergesort(a,n,mid,right);
        _merge(a,left,mid,right);
    }
}
int a[maxn],n;
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    mergesort(a,n,0,n);
    for(int i=0;i<n;++i)
    {
        if(i) cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    cout<<cnt<<endl;
    return 0;
}
