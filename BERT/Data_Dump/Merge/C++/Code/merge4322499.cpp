#include<bits/stdc++.h>
using namespace std;

int cnt=0;

void merge(int A[], int left, int mid, int right){
    int i,j,k;
    int n1=mid-left;
    int n2=right-mid;
    int L[1000000],R[1000000];
    for(i=0;i<n1;i++) L[i]=A[left+i];
    for(i=0;i<n2;i++) R[i]=A[mid+i];
    L[n1]=1000000000;
    R[n2]=1000000000;

    i=0;j=0;
    for(k=left;k<right;k++){
        cnt++;
        if(L[i]<=R[j]){
            A[k]=L[i];
            i=i+1;
        }
        else{
            A[k]=R[j];
            j=j+1;
        }
    }

}

void mergesort(int A[], int left, int right){
    if(left+1<right){
        int mid = (left+right)/2;
        mergesort(A, left, mid);
        mergesort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(){
    int n, A[2000000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }

    mergesort(A, 0, n);
    for(int j=0;j<n;j++){
        if(j==n-1) cout<<A[j]<<endl;
        else cout<<A[j]<<" ";
    }

    cout<<cnt<<endl;
    return 0;
}
