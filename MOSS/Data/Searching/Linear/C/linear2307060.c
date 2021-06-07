#include<stdio.h>
#include<stdlib.h>

int main(){

  int n,q,i,j,count=0;
  int *S,*T;

  scanf("%d",&n);
  S = malloc(sizeof(int)*n);

  for(i=0;i<n;i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);
  T = malloc(sizeof(int)*q);

  for(i=0;i<q;i++)
    scanf("%d",&T[i]);

  for(i=0;i<q;i++){
    for(j=0;j<n;j++)
      if(S[j]==T[i]){
	count++;
	break;
      }}

  printf("%d\n",count);

  free(S);
  free(T);
  return 0;
}
