#include<stdio.h>
long size=0;
int main(){
  int n;
  int q;
  int i;
  int j;
  int binarySearch(int *,int);
  int count=0;
  int S[100000];
  int T[50000];

  scanf("%d",&n);  
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  size = i;
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++){
    if(binarySearch(S,T[i]) == 1) count++;
  }
  printf("%d\n",count);
  return 0;
}

int binarySearch(int *A,int key){
  int left = 0;
  long right = size;
  int mid;
  
  while(left < right){
    mid = (left + right)/2;
    if(A[mid] == key) return 1;
    else if(key < A[mid]) right = mid;
    else  left = mid + 1;
  }
  return 0;
}

