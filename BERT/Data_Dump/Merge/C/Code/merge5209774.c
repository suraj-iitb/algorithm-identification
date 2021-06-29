#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 500000
#define INFTY 1000000001

int n,count=0;
int L[N],R[N];

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int main(){
  int i,A[N];
 scanf("%d",&n);

 for(i=0;i<n;i++){
  scanf(" %d",&A[i]);
}
 mergeSort(A,0,n);

 for(i=0;i<n;i++){
   printf("%d",A[i]);
   if(i!=n-1){
     printf(" ");
   }
 }
 printf("\n");
 printf("%d\n",count);

 return 0;
}


void merge(int *A,int l,int m,int r){
  int n1,n2,i,j,k;
  n1=m-l;
  n2=r-m;

  for(i=0;i<n1;i++){
    L[i]=A[l+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[m+i];
  }
  L[n1]=INFTY;R[n2]=INFTY;
  i=0;
  j=0;

  for(k=l;k<r;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
    i=i+1;
    }
    else{
      A[k]=R[j];
      j=j+1;
    }
    count++;
  }
}

void mergeSort(int *A,int l,int r){
  int m;
  if(l+1<r){
    m=(l+r)/2;
    mergeSort(A,l,m);
    mergeSort(A,m,r);
    merge(A,l,m,r);
  }
}

