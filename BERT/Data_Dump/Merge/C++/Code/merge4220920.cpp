#include<bits/stdc++.h>
using namespace std;
const int maxx=0x3f3f3f3f;
int n,cnt;
int L[250005],R[250005];
void merge(int A[],int n,int left,int mid,int right)
{
    int n1=mid-left;
    int n2=right-mid;
    for(int i=0;i<n1;i++) L[i]=A[left+i];
    for(int i=0;i<n2;i++) R[i]=A[mid+i];
    int i=0;
    int j=0;
    R[n2]=L[n1]=maxx;
    for(int k=left;k<right;k++)
    {
        if(L[i]<R[j])
        {
            cnt++;
            A[k]=L[i];
            i++;
        }
        else
        {
            cnt++;
            A[k]=R[j];
            j++;
        }
    }
}
void mergesort(int A[],int n,int left,int right)
{
    if(left+1>=right) return ;
    int mid=(left+right)/2;
    mergesort(A,n,left,mid);
    mergesort(A,n,mid,right);
    merge(A,n,left,mid,right);
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    int A[500005];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    mergesort(A,n,0,n);
    
    for(int i=0;i<n;i++)
    {
        if(i) cout<<" ";
        cout<<A[i];
    }
    cout<<endl<<cnt<<endl;
    return 0;
}
