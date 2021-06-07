#include<stdio.h>
#define N 100000

int S[N], n1;

int BinarySearch(int);

int main(){
  int T[N],  C[N], n2, i, j, count=0;

  scanf("%d", &n1);
  for(i =0; i < n1; i++)
    scanf("%d", &S[i]);

  scanf("%d", &n2);
  for(i = 0; i < n2; i++){
    scanf("%d", &T[i]);
    if(BinarySearch(T[i]) == 1)
      count++;
  }

  

  printf("%d\n", count);

  return 0;
}

int BinarySearch(int x){
  int l=0, r=n1, mid;

  while(l < r){
    mid = (l+r)/2;
    if(S[mid] == x)
      return 1;
    else if(x < S[mid])
      r = mid;
    else
      l = mid+1;
  }
  return 0;
}
