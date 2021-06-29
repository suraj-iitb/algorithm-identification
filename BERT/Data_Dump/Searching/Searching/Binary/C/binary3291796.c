#include <stdio.h>
#include <stdlib.h>

int binarySearch(int,int *,int);

int main(){
  int i,n,m,*A,*B,count = 0;
  
  scanf("%d",&n);
  A = (int *)malloc(n * sizeof(int));
  for(i = 0;i < n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&m);
  B = (int *)malloc(m * sizeof(int));
  for(i = 0;i < m;i++){
    scanf("%d",&B[i]);
  }
  
  for(i = 0;i < m;i++) count += binarySearch(B[i],A,n);

  printf("%d\n",count);
  

  return 0;
}


int binarySearch(int b,int *a,int n){
  int left = 0,right = n,mid;
  while(left < right){
    mid = (left + right) / 2;
    if(a[mid] == b) return 1;
    else if(b < a[mid]) right = mid;
    else left = mid + 1;
  }
  return 0;
  
}

