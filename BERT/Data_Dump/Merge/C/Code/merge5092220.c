#include<stdio.h>

#define MAX 500000
#define INFTY 1000000001

int A[MAX];

int merge(int, int, int);

int merge_sort(int, int);

int main(void){

  int i,n,count;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d", &A[i]);
  }

  count = merge_sort(0,i);

  for(i=0; i<n; i++){

    if(i != n-1){
      printf("%d ",A[i]);
    }

    else{
      printf("%d\n",A[i]);
    }

  }

  printf("%d\n",count);


  return 0;
}

int merge(int left, int mid, int right){

  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1],R[n2];
  int i,j,k;
  static int cnt=0;

  for(i=0; i<n1; i++){
    L[i] = A[left+i];
  }

  for(i=0; i<n2; i++){
    R[i] = A[mid+i];
  }

  L[n1] = INFTY;
  R[n2] = INFTY;
  i = j = 0;

  for(k=left; k<right; k++){

    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }

    else{
      A[k] = R[j];
      j++;
    }

    cnt++;
  }

  return cnt;
}


int merge_sort(int left,int right){

  int a,mid;

  if(left+1 < right){
     mid = (left+right)/2;
    merge_sort(left,mid);
    merge_sort(mid,right);
    a = merge(left,mid,right);
  }

  return a;
}

