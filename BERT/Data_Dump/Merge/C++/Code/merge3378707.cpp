#include<iostream>
using namespace std;
#define MAX 500000
#define SENTINEL 2000000000

int L[MAX/2+2], R[MAX/2+2];
int cnt=0;

void merge(int A[], int l, int m, int r)
{
    int n1, n2, i, j, k;
    n1 = m-l+1;
    n2 = r-m;
    for(i=0;i<n1;i++) L[i]=A[l+i];
    for(i=0;i<n2;i++) R[i]=A[m+i+1];
   
    i=0, j=0, k=l;
    while(i<n1 && j<n2)
    {
        cnt++;
        if(L[i]<=R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++];
        k++;
    }
    while(i<n1)
    {
        A[k++] = L[i++];
        cnt++;       
    } 
    while(j<n2)
    {
    A[k++] = R[j++];
    cnt++;
    }
}
        

void meregeSort(int A[], int l, int r)
{
    if(l<r)
    {
        int m = (l+r)/2;
        meregeSort(A, l, m);
        meregeSort(A, m+1, r);

        merge(A, l, m, r);
    }
}

int main()
{
    int A[MAX], n, i;
    cin>>n;
    for(i=0; i<n; i++) cin>>A[i];
    meregeSort(A, 0, n-1);
   
    for(i=0; i<n; i++)
    {
        if(i)cout<<" ";
        cout<<A[i];
    }
    cout<<endl;
    cout<<cnt<<endl;
    return 0;
}
