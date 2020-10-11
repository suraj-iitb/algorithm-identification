#include<stdio.h>
#define MAX_ELEMENTS 100001
#define INFTY  1000000001

typedef struct {
  char m;
  int n;
} Card;

Card L[50000],R[50000];
int n;

void swap(Card *A,Card *B){
  Card t;
  t=*A;
  *A=*B;
  *B=t;
}

void merge(Card *A,int left,int mid,int right){
  
    int n1, n2,i,j,k;

    n1 = mid - left;
    n2 = right - mid;

    for(i=0; i<=n1-1; i++)  L[i] = A[left + i];
    for(i=0; i<=n2-1; i++)  R[i] = A[mid + i];
    
    L[n1].n = INFTY;
    R[n2].n = INFTY;

    i = 0;
    j = 0;

    for(k=left; k<=right-1; k++){
        if(L[i].n<=R[j].n) A[k] = L[i++];
        else               A[k] = R[j++];
    }
}

void mergeSort(Card *A,int left,int right){
    int mid;
    if(left+1 < right){
        mid = left+(right-left)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int partition(Card *A,int p,int r){

int pivot, i, j;

//右端の要素を枢軸に

pivot=A[r].n;
i=p-1;

    for(j=p;j<r;j++){
        if(A[j].n<=pivot){
        i=i+1;
        swap(&A[i],&A[j]);
        }
    }
    swap(&A[i+1],&A[r]);
    return i+1;
}

void quicksort(Card *A,int p,int r){
    int q;
    if(p < r){
        q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}

int main(void){

    int i,flag=0;
    char S[10];
    Card A[MAX_ELEMENTS],B[MAX_ELEMENTS];

    scanf("%d", &n);
    for(i=0; i<n; i++){
    scanf("%s %d", &S, &A[i].n);
    B[i].m = A[i].m = S[0];
    B[i].n = A[i].n;
    }

    quicksort(A, 0, n-1);
    mergeSort(B, 0, n);

    for(i=0;i<n;i++){
        if(A[i].m!=B[i].m) flag=1;
    }
    if(flag==1) printf("Not stable\n");
    else        printf("Stable\n");
    for(i=0;i<n;i++) printf("%c %d\n", A[i].m, A[i].n);
    return 0;
}
