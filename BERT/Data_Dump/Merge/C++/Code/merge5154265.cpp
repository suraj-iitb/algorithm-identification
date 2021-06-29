#include<iostream>
using namespace std;
#define MAX 500000
#define SENTINEL 2000000000

int A[MAX/2+2],B[MAX/2+2];
int cnt;

void merge(int C[], int n, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    
    for(int i=0;i<n1;i++)A[i]=C[left + i];
    for(int i=0;i<n2;i++)B[i]=C[mid + i];
    A[n1]=B[n2]=SENTINEL;
    int i=0,j=0;
    for(int k=left;k<right;k++){
        cnt++;
        if(A[i]<=B[j]){
            C[k]=A[i++];
        }else{
            C[k]=B[j++];
        }
    }
}

void mSort(int A[], int n, int left, int right){
    if(left+1 < right){
        int mid = (left+right)/2;
        mSort(A,n,left,mid);
        mSort(A,n,mid,right);
        merge(A,n,left,mid,right);
    }
}

int main(){
    int D[MAX],n,i;
    cnt=0;
    
    cin>>n;
    for(i=0;i<n;i++)cin>>D[i];
    mSort(D,n,0,n);
    
    for(i=0;i<n;i++){
        if(i)cout<<" ";
        cout<<D[i];
    }
    cout<<endl;
    cout<<cnt<<endl;
    
    return 0;
}



