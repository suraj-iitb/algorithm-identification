#include<stdio.h>
#include<stdlib.h>
#define S 10000
#define T 500

int main()
{
  int n,q,i,j,cnt = 0;
  int A[S],B[T];

  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&A[i]);
    if(A[i] < 0 || A[i] > 1000000000)exit(1);
  }

  scanf("%d",&q);
  for(i = 0 ; i < q ; i++){
    scanf("%d",&B[i]);
    if(B[i] < 0 || B[i] > 1000000000)exit(1);
  }

  for(i = 0 ; i < q ; i++){
    for(j = 0 ; j < n ; j++){
      if(A[j] == B[i]){
	cnt++;
	break;
      }
    }
  }
  printf("%d\n",cnt);
  return 0;
}
  
    

