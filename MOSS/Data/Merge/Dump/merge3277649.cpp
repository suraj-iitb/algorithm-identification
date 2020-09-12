#include <bits/stdc++.h>
using namespace std;

const int INF=2000000000; 

int cnt;

void merge(int *A,int l,int mid,int r){
    int n1=mid-l;
    int n2=r-mid;
    int L[n1+1],R[n2+1];
    for(int i=0;i<n1;i++) L[i]=A[l+i];
    for(int i=0;i<n2;i++) R[i]=A[mid +i];
    L[n1]=INF;
    R[n2]=INF;
    int i=0,j=0;
    for(int k=l;k<r;k++){
        cnt++;
        if(L[i]<=R[j]) A[k]=L[i++];
        else A[k]=R[j++];
    }
}

void mergesort(int *A,int l,int r){
    if(l+1<r){
        int mid=(l+r)/2;
        mergesort(A,l,mid);
        mergesort(A,mid,r);
        merge(A,l,mid,r);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    mergesort(a,0,n);
    for(int i=0;i<n;i++){
        cout<<a[i];
        if(i!=n-1)cout<<' ';
        else cout<<endl;
    }
    cout<<cnt<<endl;
}
