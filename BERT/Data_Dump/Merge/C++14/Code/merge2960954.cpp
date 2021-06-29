#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000010

using namespace std;

int n, a[500010], cnt=0;

void merge (int left, int mid, int right)
{
    int n1=mid-left, n2=right-mid, L[n1+1], R[n2+1];
    for (int i=0; i<n1; i++) L[i]=a[left+i];
    for (int i=0; i<n2; i++) R[i]=a[mid+i];
    L[n1]=INF; R[n2]=INF;
    int i=0, j=0;
    for (int k=left; k<right; k++)
    {
        cnt++;
        if (L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
    }
}

void mergesort (int left, int right)
{
    if (left+1<right)
    {
        int mid=(left+right)/2;
        mergesort(left, mid);
        mergesort(mid, right);
        merge(left, mid, right);
    }
}
int main()
{
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    mergesort(0, n);
    for (int i=0; i<n; i++)
    {
        if (i!=n-1) cout<<a[i]<<' ';
        else cout<<a[i]<<'\n';
    }
    cout<<cnt<<'\n';
    return 0;
}

