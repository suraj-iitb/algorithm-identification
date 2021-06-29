#include<stdio.h>
#include<math.h>
#define MAX 500000

void merge(int,int);
void mergesort(int, int);

int A[MAX],kei=0;

int main (){
    int i,n;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    mergesort(0,n);
    for(i=0;i<n;i++){
        if(i!=n-1)printf("%d ",A[i]);
        else printf("%d\n",A[i]);
    }
    printf("%d\n",kei);
    return 0;

}

void merge(int left,int right){
    int mid,n1,n2;
    double L[MAX],R[MAX];
    int k,j,i;
    mid=(right+left)/2;
    n1 = mid - left;
    n2 = right - mid;
    for(i=0;i<n1;i++){
        L[i]=A[left+i];
    }
    for(i=0;i<n2;i++){
        R[i]=A[mid+i];
    }
    L[n1]=10000000000000;
    R[n2]=10000000000000;

    i=0;
    j=0;
    for(k=left;k<right;k++){
        kei++;
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }
        else{
            A[k]=R[j];
            j=j+1;
        }
    }

}
void mergesort(int left,int right){
    int mid;
    if(left+1<right){
        mid=(left+right)/2;
        mergesort(left,mid);
        mergesort(mid,right);
        merge(left,right);
    }

}

