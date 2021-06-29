#include<stdio.h>
#define N 500000
#define M 2000000000


int L[N/2+2],R[N/2+2];
int count=0;


void merge(int A[],int l,int m,int r){
  int i,j,k;
  int n1;
  int n2;
  n1 = m - l;
  n2 = r - m;
  for(i=0;i<n1;i++){
    L[i] = A[l+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[m+i];
  }
  L[n1] = R[n2]=M;
  i = j = 0;
  for(k=l;k<r;k++){
    count++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }
      else {
	A[k] = R[j];
	j++;
      }
  }
}


void mergesort(int A[],int l,int r){
  int m;
  if(l+1<r){
    m = (l+r)/2;
    mergesort(A,l,m);
    mergesort(A,m,r);
    merge(A,l,m,r);
  }
}


int main(){
  int i,a,b[N];
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&b[i]);
  }
  mergesort(b,0,a);
  for(i=0;i<a-1;i++){
    //if(i>=1) printf(" ");
    printf("%d ",b[i]);
  }
  printf("%d\n",b[a-1]);
  printf("%d",count);
  printf("\n");
  return 0;
}
