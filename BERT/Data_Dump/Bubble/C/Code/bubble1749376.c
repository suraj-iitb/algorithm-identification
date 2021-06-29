#include <stdio.h>
int main(){

  int i,j,N[100],loop,count=0,num;

  scanf("%d",&loop);

  for(i=0; i<loop; i++){
    scanf("%d",&N[i]);
  }

  for(i=0; i<loop-1; i++){
    for(j=loop-1; j>i; j--){
      if(N[j-1]>N[j]){
	num = N[j-1];
	N[j-1] = N[j];
	N[j] = num;
	count++;
      }
    }
  }

  for(i=0; i<loop-1; i++){
    printf("%d ",N[i]);
  }
  printf("%d\n",N[i]);
  printf("%d\n",count);

  return 0;
}
