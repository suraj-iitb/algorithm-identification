#include <stdio.h>

#define MAX 500000
void merge(int A[],int l,int m,int r);
void mergesort(int A[],int l,int r);

int n,c=0;
int L[MAX/2+2],R[MAX/2+2];

int main(){
  int i;
  int A[MAX];

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);

  mergesort(A,0,n);

  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }

  printf("\n");

  printf("%d\n",c);

  return 0;
}

void merge(int A[],int l,int m,int r){
  int n1,n2,i,j,k;
  n1=m-l;
  n2=r-m;
  for(i=0;i<n1;i++) L[i]=A[l+i];
  for(i=0;i<n2;i++) R[i]=A[m+i];
  L[n1]=R[n2]=2000000000;
  i=0,j=0;
  for(k=l;k<r;k++){
    c++;
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }else{
      A[k]=R[j];
      j++;
    }
  }
}
void mergesort(int A[],int l,int r){
  if(l+1<r){
    int m;
    m=(l+r)/2;
    mergesort(A,l,m);
    mergesort(A,m,r);
    merge(A,l,m,r);
  }
}


