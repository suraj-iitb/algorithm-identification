#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000000

int main(){
  int n,q,*S,*T,i,j,count=0,key;

  S=malloc(MAX);
  T=malloc(MAX);

  scanf("%d",&n);

  for(i=0;i<n;i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);

 
  
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);

    j=0;

    S[n] = T[i];
    
    while(S[j] != T[i]){
	j++;
    }
      
      if(j!=n)count++;
      else count += 0;
  }
  
  printf("%d\n",count);

  free(S);
  free(T);
    
  return 0;
  
}


