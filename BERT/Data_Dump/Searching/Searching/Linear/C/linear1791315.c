#include<stdio.h>
#define N 10000
#define Q 500

int main(){
  int s,t,S[N],T[Q],i,j,count=0;
  
  scanf("%d",&s);

  for(i=0 ; i<s ; i++)scanf("%d",&S[i]);
  
  scanf("%d",&t);
  
  for(i=0 ; i<t ; i++)scanf("%d",&T[i]);
  
  for(i=0;i<t;i++){
    for(j=0;j<s;j++){
      if(S[j]==T[i]){
	count++;
	break;
      }
    }
  }
  printf("%d\n",count);
  return 0; 
}
