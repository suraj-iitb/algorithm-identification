#include<stdio.h>

#define LE 250001
#define RI 250001
#define N 500000
#define INFTY 2100000000

//void merge(int *,int,int,int);
//void margeSort(int *,int,int);
int g=0;

void merge(int *A, int left,int mid,int right){
  int i,L[LE],R[RI],k,j,n1,n2;
  //printf("???????????????\n\n");
  n1 = mid - left;
  n2 = right - mid;

  //L[0...n1], R[0...n2] ?????????

  for(i=0;i<n1;i++) L[i] = A[left+i];
  for(i=0;i<n2;i++) R[i] = A[mid+i];

 /* for(i = 0; i<(n1-1);i++){
    L[i] = A[left + i];
    printf("???????????????\n\n");
  }*/

 // for(i = 0;i<(n2-1);i++){
    //printf("???????????????\n\n");
    //R[i] = A[mid + i];
    L[n1] = INFTY;
    R[n2] = INFTY;
    i = 0;
    j = 0;
  //}

  for(k = left;k<right;k++){
    g++;
    if( L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else{
      A[k] = R[j];
      j = j + 1;
    }
  }
  }

void mergeSort(int *A,int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}


int main(){
  int n,a[N],i,m;

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&a[i]);

  //m = (n-1)/2;

  mergeSort(a,0,n);

  for(i=0;i<n-1;i++) printf("%d ",a[i]);
  printf("%d\n",a[n-1]);
  printf("%d\n",g);
  return 0;
}
