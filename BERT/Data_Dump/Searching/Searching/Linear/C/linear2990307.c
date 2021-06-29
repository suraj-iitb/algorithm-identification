#include<stdio.h>

int main(){

  int n,S[10000],q,T[500],i,j,count=0,same;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(j=0;j<q;j++){
    for(i=0;i<n;i++){
      if(S[i]==T[j]){
	count++;
	break;
      }
      // if(S[i]==T[j]==same) count--;
    }
  }

 
  
  printf("%d\n",count);
}

