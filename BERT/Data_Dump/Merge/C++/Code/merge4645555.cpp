#include<stdio.h>
#define MAX 500000
#define SENTINEL 2000000000
using namespace std;

int sum=0;

void merge(int A[], int left, int mid, int right){
    int n1,n2;
    n1=mid-left;
    n2=right-mid;
    int L[n1]={0},R[n2]={0};
    for(int i=0;i<n1;i++){
        L[i]=A[left+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=A[mid+i];
    }
    L[n1]=R[n2]=2000000000;
    int i=0,j=0;
    for(int k=left;k<right;k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
            sum++;
        }else{
            A[k]=R[j];
            j++;
            sum++;
        }
    }
}


void mergeSort(int A[], int left, int right){
    int mid;
    if(left+1<right){
        int mid=(left+right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(){
    int n;
    int S[500000]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    mergeSort(S,0,n);
    for(int i=0;i<n;i++){
        if(i) printf(" ");
        printf("%d", S[i]);
    }
    printf("\n");
    printf("%d\n", sum);
}
