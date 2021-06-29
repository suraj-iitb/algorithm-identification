#include<stdio.h>
#define MAX 500000
#define INFTY 1000000000

void merge(int *,int,int,int);
void mergesort(int *,int,int);

int n,num[MAX],count=0;

int main() {

  int i;
  
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&num[i]);

  mergesort(num,0,n);

  for(i=0;i<n;i++) {
    if(i>0) printf(" ");
    printf("%d",num[i]);
  }
  printf("\n%d\n",count);

  return 0;

}


void merge(int *A, int left, int mid, int right) {

  int i,j,k;
  int n1 = mid - left;
  int n2 = right -mid;

  int L[n1],R[n2];

  for(i=0;i<n1;i++) L[i] = A[left+i];
  for(i=0;i<n2;i++) R[i] = A[mid+i];

  L[n1] = INFTY;
  R[n2] = INFTY;

  i=j=0;

  for(k=left;k<right;k++) {
    if( L[i] <= R[j]) {
      A[k] = L[i];
      i+=1;
    } else {
      A[k] = R[j];
      j+=1;
    }
    count++;
  }
}

void mergesort(int *A, int left, int right) {
  
  if( left+1 < right ) {
    int mid = ( left + right )/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
  
}
