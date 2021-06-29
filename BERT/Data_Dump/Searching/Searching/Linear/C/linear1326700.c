#include <stdio.h>

int main(){
  int S[10000], count = 0, s, t, t0, i, j;
  scanf("%d",&s);
  for(i = 0; i < s; i++) scanf("%d",&S[i]);
  scanf("%d",&t);
  for(i = 0; i < t; i++){
    scanf("%d",&t0);
    for(j=0; j < s; j++){
      if(S[j] == t0){
	count++;
	break;
	  }
	}
  }
  printf("%d\n",count);
  return 0;
}
