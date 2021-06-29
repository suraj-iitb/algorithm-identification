#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;
#define MAX 500000;
#define SENTINEL 2000000000;
//int count=0;

void merge(int A[], int left, int mid, int right){
    int n1=mid-left;
    int n2=right-mid;
    int L[500000/2+2],R[500000/2+2];
    for(int i=0;i<n1;i++) L[i]=A[left+i];
    for(int i=0;i<n2;i++) R[i]=A[mid+i];
    L[n1]=SENTINEL;
    R[n2]=SENTINEL;
    int i=0,j=0;
    for(int k=left;k<right;k++){
//        count++;
        if(L[i]<=R[j]){
            A[k]=L[i++];
        }else{
            A[k]=R[j++];
        }
    }

};

void mergeSort(int A[], int left, int right){
    if (left+1<right){
        int mid=(left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
}

int partition(int A[], int p, int r){
    int x=A[r];
    int i=p-1;
    for(int j=p; j<r; j++){
        if (A[j]<=x){
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

void quicksort(int A[], int p, int r){
    if(p<r){
        int q = partition(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}

int C[2000001];
int k=10000;
void countingSort(int A[], int B[], int n){
    for(int i=0;i<k;i++)C[i]=0;
    for(int j=1;j<=n;j++)C[A[j]]++;
    for(int i=1;i<k;i++)C[i]=C[i]+C[i-1];
    for(int j=n;j>0;j--){
        B[C[A[j]]]=A[j];
        C[A[j]]--;
    }

}
int main()
{
    int n,i;
    scanf("%d",&n);
    int A[n+1];
    int B[n+1];
    for(int i=0;i<n;i++)scanf("%d",&A[i+1]);
    countingSort(A,B,n);
    for(i=1;i<=n;i++){
        if(i>1) cout<<" ";
        cout<<B[i];

    }
    cout<<endl;
    return 0;
}
