#include <stdio.h>
#include <stdlib.h>

int main(){
  int *S;
  int n;
  int q;
  int *T;
  int i,j;
  int jg=0;

  scanf("%d",&n);
  S=(int *)malloc(n*sizeof(int));

  for(i=0;i<n;i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  T=(int *)malloc(q*sizeof(int));

  for(i=0;i<q;i++)scanf("%d",&T[i]);
  
  for(j=0;j<q;j++){
    for(i=0;i<n;i++){
      if(S[i]==T[j]){
	jg++;
	break;
      }
    }
  }
  printf("%d\n",jg);
  return 0;
}

     
    
      

