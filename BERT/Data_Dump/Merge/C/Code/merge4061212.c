#include <stdio.h>
#include <math.h>


#define N 500000
#define SENTINEL 1000000000

int num,L[N/2+2],R[N/2+2];
int cnt=0;

void merge(int [],int,int,int);
void mergeSort(int [],int,int);

int main(){
    int i,j;
    int l,m,r;
    int A[N];

    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("%d",&A[i]);
    }
    l=0;

    mergeSort(A,0,num);
    for(i=0;i<num;i++){
        if(i) printf(" ");
        printf("%d",A[i]);
    }
    printf("\n");
    printf("%d\n",cnt);
    return 0;
}

void merge(int A[],int l,int m,int r){
    int n1,n2;
    int i,j,k;

    n1 = m-l;
    n2 = r-m;

    for(i=0;i<n1;i++){
        L[i] = A[l+i];
    }
    for(j=0;j<n2;j++){
        R[j] = A[m+j];
    }
    L[n1] = SENTINEL;
    R[n2] = SENTINEL;

    i=j=0;
    for(k=l;k<r;k++){
        cnt++;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int A[],int l,int r){
    int mid;
    if(l+1<r){
        mid = (l+r)/2;
        mergeSort(A,l,mid);
        mergeSort(A,mid,r);
        merge(A,l,mid,r);
    }
}
