#include<bits/stdc++.h>
using namespace std;
int cnt;
int L[250002],R[250002];

void merge(int A[],int n,int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    for(int i=0;i<n1;i++)L[i]=A[left+i];
    for(int i=0;i<n2;i++)R[i]=A[mid+i];
    L[n1]=2000000000;
    R[n2]=2000000000;

    int i=0,j=0;
    for(int k=left;k<right;k++){
        cnt++;
        if(L[i]<=R[j]){
            A[k]=L[i++];
        }
        else{
            A[k]=R[j++];
        }
    }
}
void mergeSort(int A[],int n,int left,int right){
    if(left+1<right){
        int mid=(left+right)/2;
        mergeSort(A,n,left,mid);
        mergeSort(A,n,mid,right);
        merge(A,n,left,mid,right);
    }
}

int main(){
    int A[500000];
    int n,i;
    cnt=0;
    cin>>n;
    for(i=0;i<n;i++)cin>>A[i];

    mergeSort(A,n,0,n);

    for(i=0;i<n;i++){
        if(i)cout<<" ";
        cout<<A[i];
    }
    cout<<endl;
    cout<<cnt<<endl;

    return 0;
}
