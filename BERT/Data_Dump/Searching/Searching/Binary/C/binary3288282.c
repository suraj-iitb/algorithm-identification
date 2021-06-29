#include<stdio.h>

int binarySearch(int, int *, int);

int main(){

  int i, n, q, key, cnt=0;

  scanf("%d", &n);

  int S[n];

  for(i=0;i<n;i++) scanf("%*c%d", &S[i]);

  scanf("%d", &q);

  int T[q];

  for(i=0;i<q;i++) scanf("%*c%d", &T[i]);

  for(i=0;i<q;i++){

    key=binarySearch(n, S, T[i]);

    if(key) cnt++;

  }

  printf("%d\n", cnt);

  return 0;

}

int binarySearch(int n, int *A, int key){

  int mid, left=0, right=n;

  while(left<right){

    mid=(left+right)/2;

    if(key==A[mid]) return 1;

    else if(key>A[mid]) left=mid+1;

    else right=mid;

  }

  return 0;

}

