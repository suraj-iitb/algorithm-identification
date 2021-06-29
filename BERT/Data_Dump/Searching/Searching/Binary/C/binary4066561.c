#include<stdio.h>
#include<stdlib.h>
#define S 100000
#define T 50000

int main()
{
  int n,q,i,j,cnt = 0;
  int A[S],B[T];
  int left,right,mid;

  scanf("%d",&n);
  if(n > 100000)exit(1);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&A[i]);
    if(A[i] < 0 || A[i] > 1000000000)exit(1);
    else if(A[i - 1] > A[i])exit(1);
  }

  scanf("%d",&q);
  if(q > 50000)exit(1);
  for(i = 0 ; i < q ; i++){
    scanf("%d",&B[i]);
    if(B[i] < 0 || B[i] > 1000000000)exit(1);
    for(j = 0 ; j < i ; j++){
        if(B[i] == B[j])exit(1);
    }
  }

  for(i = 0 ; i < q ; i++){
  left = 0;
  right = n;
      while(left < right){
          mid = (left + right) / 2;
          if(A[mid] == B[i]){
              cnt++;
              break;
          }
          else if(B[i] < A[mid])right = mid;
          else left = mid + 1;
      }
  }

  printf("%d\n",cnt);
  return 0;
}

