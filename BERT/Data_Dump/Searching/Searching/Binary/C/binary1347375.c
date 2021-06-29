#include<stdio.h>
#define MAX 100000

int main(void){
  int S[MAX],T[MAX],n,q,count=0,i,left,mid,right;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  /* for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(S[j] == T[i]){
	count++;
	break;            //codesA.c で用いたプログラム
      }
    }
  }
  printf("%d\n",count);
  */
  for(i=0;i<q;i++){
    left = 0;
    right = n;
    while(left < right){
      mid = (left + right-1) / 2;
      if(S[mid] == T[i]){
	count++;
	break;
      }
      else if(T[i] < S[mid]){
	right = mid;
      } else{
	left = mid + 1;
      }
    }
  }
  printf("%d\n",count);
  return 0;  
}
