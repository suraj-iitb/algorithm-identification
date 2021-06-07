#include<stdio.h>

int S[100000];
int n;

int binarySearch(int key){
  int left=0;
  int right=n;
  while(left < right){
    int mid;
    mid = (left+right)/2;
    if(S[mid]==key) return 1;
    else if(key<S[mid]) right = mid;
    else left = mid + 1;
  }
  return 0;
}

int main(){
  int q, T, i, count=0;

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  for(i=0; i<q; i++){
    scanf("%d", &T);
    if(binarySearch(T)){
      count++;
    }
  }

  printf("%d\n", count);
  return 0;
}


