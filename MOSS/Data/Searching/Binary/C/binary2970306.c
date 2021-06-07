#include<stdio.h>

int A[1000000],n;

/* 二分探索 */
int binarySearch(int key){
  int left = 0, right = n, mid;
  
  while(left < right){
    mid = (left + right) /2;
    if(A[mid] == key) return 1;
    else if(A[mid] < key) left = mid + 1;
    else right = mid;
  }
  
  return 0;
}

int main(){
  int i, q, key, sum=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(binarySearch(key)) sum++;
  }

  printf("%d\n",sum);

  return 0;
}

