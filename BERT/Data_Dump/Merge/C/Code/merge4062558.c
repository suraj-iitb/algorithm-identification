#include<stdio.h>
#include<math.h>

#define N 501000

int merge(int *,int,int,int);
int mergeSort(int *,int,int);

int main(void){
  int n,cnt,S[N];
  int i;
  
  scanf(" %d",&n);
  for(i = 0; i < n; i++){
    scanf(" %d",&S[i]);
  }

  cnt = mergeSort(S,0,n);

  for(i = 0; i < n; i++){
    if(i > 0)printf(" ");
    printf("%d",S[i]);
  }
  printf("\n");
 
  printf("%d\n",cnt);
  
  return 0;
}

int merge(int *A, int left, int mid, int right){
  int n1,n2,cnt=0,L[N/2],R[N/2];
  int i,j,k;

  n1 = mid - left;
  n2 = right - mid;

  for(i = 0; i < n1; i++){
    L[i] = A[left+i];
  }
  /*
  if(A[left] == 0) printf("left: %d\n",left);
  if(A[mid] == 0) printf("mid: %d\n",mid);
  if(A[right] == 0) printf("right: %d\n",right);
  */
  /*  
  for(i = 0; i < n1; i++){
    printf("L[%d]:",i);
    printf("%d ",L[i]);
  }
  printf("\n");
  */
  for(i = 0; i < n2; i++){
    R[i] = A[mid+i];
  }
  /*
  for(i = 0; i < n2; i++){
    printf("R[%d]:",i);
    printf("%d ",R[i]);
  }
  printf("\n");
  */
  L[n1] = (int)INFINITY;
  R[n2] = (int)INFINITY;
  i = 0;
  j = 0;
  for(k = left; k < right; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
      cnt++;
    }
    else{
      A[k] = R[j];
      j++;
      cnt++;
    }
    //if(A[k] == 0) printf("k: %d\n",k);
  }
  //printf("right.500000: %d\n",A[500000]);
  return cnt;
}

int mergeSort(int *A, int left, int right){
  int mid,cnt=0;
  int i;
  if(left+1 < right){
    mid = (left+right)/2;
    cnt += mergeSort(A,left,mid);
    cnt += mergeSort(A,mid,right);
    cnt += merge(A,left,mid,right);
  }
  return cnt;
}

