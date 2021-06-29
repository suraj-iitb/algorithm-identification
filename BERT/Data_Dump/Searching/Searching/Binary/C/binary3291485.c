#include<stdio.h>

int binarySearch(int, int[], int);

int main(){
  int n,i,q,key,count=0;
  int S[100001];

  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&key);
    if(binarySearch(n, S, key) != -1) count++;
  }
  printf("%d\n",count);
  
  return 0;
}

int binarySearch(int n, int A[], int key){
  int left = 0;
  int right = n;
  int mid;

  while(left < right){
    mid = (left + right) / 2;
    if(A[mid] == key) return mid;
    else if(key < A[mid]) right = mid;
    else left = mid + 1;
  }
  return -1;
}

