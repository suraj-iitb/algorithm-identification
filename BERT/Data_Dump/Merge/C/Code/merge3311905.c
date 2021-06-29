#include<stdio.h>
//#include<stdlib.h>
#define INTFY 2000000000
long int S[500000],l;

void mergesort(long int*,long int,long int);
void merge(long int*,long int,long int,long int);

int main(){
  long int n,i;
  scanf("%ld",&n);
   for(i=0;i<n;i++){
     scanf("%ld",&S[i]);
  }
  mergesort(S,0,n);
  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%ld",S[i]);
 }
 printf("\n");
    printf("%ld\n",l);
  return 0;
}

void mergesort(long int A[],long int left,long int right){
  long int mid,i;

  if(left+1<right){
    mid = (left+right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
}

void merge(long int A[],long int left,long int mid,long int right){
  long int n1=mid-left;
  long int n2=right-mid;
  long int L[500000],R[500000],i,j=0,k;
  L[n1]=INTFY;
  R[n2]=INTFY;
  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }

  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  i=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i+=1;
      l++;
    }
    else{
      A[k]=R[j];
      j=j+1;
      l++;
    }
  }
}

