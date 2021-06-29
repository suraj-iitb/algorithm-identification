#include<stdio.h>
#include<stdlib.h>

int main(){
  int i = 0 ,j,n,q,count = 0,left,right,mid;
  int *S,*T;

  scanf("%d",&n);

  S = (int *)malloc(sizeof(int) * n);

  for(i = 0 ; i < n ; i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);

  T = (int *)malloc(sizeof(int) * q);

  for(i = 0 ; i < q ; i++)
    scanf("%d",&T[i]);

  for(j = 0 ; j < q ; j++){
      left = 0;
      right = n;
      while(left < right){
	mid = (left + right) / 2;
	if(S[mid] == T[j]){
	  count++;
	  break;
	}
	else if(T[j] < S[mid])
	  right = mid;
	else
	  left = mid + 1;
      }
  }

  printf("%d\n",count);

  return 0;
}
