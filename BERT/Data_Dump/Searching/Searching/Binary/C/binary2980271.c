#include <stdio.h>
#include <stdlib.h>
#define N 1000000000
int *S, n;
int binarySearch(int);
int main(){
  int *T;
  int q;
  int i,j,k;
  int cnt = 0;
  int left,right,mid;

  scanf("%d",&n);
  if(n > 100000)
    exit(1);
  S = (int*)malloc(sizeof(int) * n);
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
    if(S[i] > N)
      exit(1);
  }

  scanf("%d",&q);
  if(q > 50000)
    exit(2);
  T = (int*)malloc(sizeof(int) * q);
  for(i = 0; i < q; i++){
    scanf("%d",&T[i]);
    if(T[i] > N)
      exit(1);
      for(j = 0; j < i; j++){
	if(T[i] == T[j]){
	  printf("Tは互いに異なる要素を入力してください\n");
	  exit(1);
	}
      }
  }

  for(i = 0; i < q; i++){
    if(binarySearch(T[i]))
      cnt++;
  }

  printf("%d\n",cnt);
  return 0;
}

int binarySearch(int key){
  int left = 0;
  int right = n;
  int mid;
  while(left < right){
    mid = (left + right) / 2;
    if(key == S[mid])
      return 1;
    else if(key < S[mid])
      right = mid;
    else
      left = mid + 1;
  }
  return 0;
}

