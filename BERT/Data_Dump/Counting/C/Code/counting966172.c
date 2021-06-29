#include<stdio.h>
 
#define N 2000000
 
int arr[N];
int n;
 
void count(int A[], int k){
  int ca[k],i,j;
  i = k;
  for(; i>=0 ; i--) ca[i] = 0;
  for(j=1; j<=n; j++) ca[A[j]]++;
  for(i=1; i<k; i++) ca[i] += ca[i-1];
  for(j=n; j>=1; j--){
    arr[ca[A[j]]] = A[j];
    ca[A[j]]--;
  }
}
 
int main(int argc,char *argv[]){
  int k=0,i;
  int A[N];
  scanf("%d",&n);
  for(i=1; i<=n; i++){
    scanf("%d",&A[i]);
  }
  k=A[1];
  for(i=2; i<=n; i++){
      if(k < A[i]) k = A[i];
  }
  count(A, k+1);
  for(i=1; i<n; i++) {
    printf("%d ",arr[i]);
  }
  printf("%d\n",arr[i]);
  return 0;
}
