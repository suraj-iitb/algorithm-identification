#include<stdio.h>
#include<stdlib.h>
#define INF 2000000000
typedef struct {
  char m;
  int n;
} Card;
int c=0;
Card L[50000],R[50000];
void swap(Card *a,Card *b){
  Card tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}
void merge(Card *A,int left,int mid,int right){
  int n1,n2,i,j,k;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];
  L[n1].n=INF;
  R[n2].n=INF;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i].n<=R[j].n){
      A[k]=L[i];
      i++;
    }
    else{
      A[k]=R[j];
      j++;
    }
    c++;
  }
}

void mergeSort(Card *A,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2 ;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
} 


int partition(Card *A,int p,int r){
  int i,j;
  Card x;
  x=A[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j].n<=x.n){
      i++;
      swap(&A[i],&A[j]);
    }
  }
  swap(&A[i+1],&A[r]);
  return i+1;
}

void quicksort(Card *A,int p,int r){
  int q;
  if(p<r){
    q=partition(A,p,r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  }
}
  
int main(){
  int i,n,flag=0;
  Card A[100000],B[100000];
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf(" %c%d",&A[i].m,&A[i].n);
    B[i]=A[i];
  }
  quicksort(A,1,n);
  mergeSort(B,1,n+1);
  for(i=1;i<=n;i++){
    if(A[i].m!=B[i].m) flag=1;
  }
  if(flag==1) printf("Not stable\n");
  else printf("Stable\n");
  for(i=1;i<=n;i++) printf("%c %d\n",A[i].m,A[i].n);
  return 0;
}

