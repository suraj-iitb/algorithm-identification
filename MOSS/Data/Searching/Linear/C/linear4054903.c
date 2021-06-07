#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000000

int main(){
  int i=0,k,n,q,*S,*T,count=0,j,flag,key;

  S = malloc(MAX);
  T = malloc(MAX);
  
  scanf("%d",&n);
  for(i=0;i<n;i++){ scanf("%d",&S[i]);

}
  scanf("%d",&q);
  for(i=0;i<q;i++)  scanf("%d",&T[i]);

  for(i=0;i<q;i++){
    j=0;
    
    key = T[i];
    S[n] = key;

    flag=1;
    while(S[j] != T[i]){
      
      j++;
      if(j == n) flag=0;
    }

    if(flag == 1) count++;
  }

  printf("%d\n",count);

  free(S);
  free(T);
  
  return 0;
}

