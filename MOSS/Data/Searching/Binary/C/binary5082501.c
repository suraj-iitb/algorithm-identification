#include<stdio.h>

int binarySearch(int);

int n, S[100000];

int main(void){
  int x, y;
  int i, cnt=0;

  scanf("%d", &n);

  for(i=0;i<n;i++)  scanf("%d", &S[i]);

  scanf("%d", &x);

  for(i=0;i<x;i++){

    scanf("%d", &y);

    if(binarySearch(y))
      cnt++;
}

  printf("%d\n", cnt);

  return 0;
}

int binarySearch(int key){


  int left = 0;
  int right = n;

  int mid;

  while(left < right){

    mid = (left + right) / 2;

    if(S[mid] == key) return 1;

    else if(key < S[mid]) right = mid;

    else if(key > S[mid]) left = mid + 1;
  }
  return 0;
}

