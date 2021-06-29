#include<stdio.h>
#define N 100000
int binarySearch(int *,int,int);

main(){
  int i,j,k,l,count=0,a[N],b,c[N],d;
  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&d);
  for(j=0;j<d;j++){
    scanf("%d",&c[j]);
  }

  for(i=0;i<d;i++){
    k = binarySearch(a,c[i],b);
    if(a[k]==c[i])count++;
  } 
  printf("%d\n",count);
  return 0;
}

int binarySearch(int *A,int key,int n){
  int left=0;
  int right=n;
  int mid;
  while(left<right){
    mid = (left + right)/2;
    if(A[mid] == key) {
      return mid;
    }
    else if(key < A[mid]) right = mid;
    else if(key > A[mid]) left = mid+1;
  }
}
