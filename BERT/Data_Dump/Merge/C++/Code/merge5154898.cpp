#include <iostream>
using namespace std;

int cnt;

void Merge(int *a, int n, int left, int mid, int right)
{
    int n1 = mid-left;
    int n2 = right-mid;
    int b1[n1+1], b2[n2+1];
    for(int i=0; i<n1; i++)
        b1[i] = a[i+left];
    for(int i=0; i<n2; i++)
        b2[i] = a[i+mid];
    b1[n1] = 2000000000, b2[n2] = 2000000000;
    int i = 0;
    int j = 0;
    for(int k=left; k<right; k++)
    {
        cnt++;
        if(b1[i]<b2[j])
            a[k] = b1[i++];
        else
            a[k] = b2[j++];
    }
}

void MergeSort(int *a, int n, int left, int right)
{
    if(right-left>1)
    {
        int mid = (left+right)/2;
        MergeSort(a, n, left, mid);
        MergeSort(a, n, mid, right);
        Merge(a, n, left, mid, right);
    }
}

int main(void)
{
    int i, n;
    cin>>n;
    int a[n];
    for(i=0; i<n; i++)
        cin>>a[i];
    cnt = 0;
    MergeSort(a, n, 0, n);
    for(i=0; i<n; i++)
    {
        if(i!=n-1)
            cout<<a[i]<<' ';
        else
            cout<<a[i]<<endl;
    }
    cout<<cnt<<endl;
}
