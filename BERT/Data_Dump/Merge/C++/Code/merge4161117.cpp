#include <iostream>
#define MAX 1000000001
using namespace std;

int sum;
void merge(int A[],int left,int mid,int right)
{
    int L[mid-left+1],R[right-mid+1];
    for(int i=0;i<mid-left;i++)
        L[i]=A[left+i];
    L[mid-left]=MAX;
    for(int i=0;i<right-mid;i++)
        R[i]=A[mid+i];
    R[right-mid]=MAX;
    int L_index=0,R_index=0;
    for(int i=left;i<right;i++)
    {
        if(L[L_index]<=R[R_index])
        {
            A[i]=L[L_index];
            L_index++;
        }
        else{
            A[i]=R[R_index];
            R_index++;
        }
        sum++;
    }
}
void mergeSort(int A[],int left,int right){
    if(left+1<right)
    {
        int mid=(left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
}
int main()
{
    int n,A[500000];
    sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>A[i];
    mergeSort(A,0,n);
    int isn=0;
    for(int i=0;i<n;i++)
    {
        if(isn++>0)
            cout<<" ";
        cout<<A[i];
    }
    cout<<endl;
    cout<<sum<<endl;
    return 0;
}
