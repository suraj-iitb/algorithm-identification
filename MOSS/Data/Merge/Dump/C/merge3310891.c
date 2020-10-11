#include<stdio.h>
#define N 500000

int A[N],B[N],count=0;

void mergeSort(int*,int,int);
    
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    mergeSort(A,0,n-1);
    for(i=0;i<n-1;i++)
        printf("%d ",A[i]);
    printf("%d\n%d\n",A[n-1],count);
    return 0;
}

void mergeSort(int *a,int l,int r){
    int i,j,k,m;
    if(r>l){
        m=(r+l)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        for(i=m+1;i>l;i--)
            B[i-1]=A[i-1];
        for(j=m;j<r;j++)
            B[r+m-j]=A[j+1];
        for(k=l;k<=r;k++){
            A[k]=(B[i]<B[j])?B[i++]:B[j--];
            count++;
        }
    }
}

