#include<stdio.h>
#include<string.h>
   
int main(){
  int S[10000];
  int T[500];
  int n,i,q,j,count=0,flag=0;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&T[i]);
  }

  for(i = 0; i < q; i++){
    for(j = 0; j < n; j++){
      if(S[j] == T[i]){
	if(flag == 0){
	  flag = 1;
	  count++;
	}
      }
    }
    flag = 0;
  }

  printf("%d\n",count);
  return 0;
}
