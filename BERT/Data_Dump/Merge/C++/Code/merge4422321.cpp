#include <iostream>
using namespace std;
int count=0;
void merge(int A[],int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    int L[n1+1],R[n2+1];
    for(int i=0;i<n1;i++){
        L[i]=A[left+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=A[mid+i];
    }
    L[n1]=10000000000;
    R[n2]=10000000000;
    int i=0,j=0;
    for(int k=left;k<right;k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
            count++;
        }
        else{
            A[k]=R[j];
            j++;
            count++;
        }
    }
}

void mergesort(int A[],int left,int right){
    if(left+1<right){
        int mid=(left+right)/2;
        mergesort(A,left,mid);
        mergesort(A,mid,right);
        merge(A,left,mid,right);
    }
}
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    mergesort(A,0,n);
    for(int i=0;i<n-1;i++){
        cout<<A[i]<<" ";
    }
    cout<<A[n-1]<<endl;
    cout<<count<<endl;
    return 0;
}
