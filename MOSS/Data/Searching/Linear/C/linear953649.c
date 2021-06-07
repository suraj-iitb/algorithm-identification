#include<stdio.h>
#define N 10000 
#define Q 500

int main(){
  int S[N],T[Q],n,q,i,j,t=0;
 
  scanf("%d",&n);
 
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
 
  scanf("%d",&q);
  
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
   
  for(i=0;i<n;i++){
    for(j=0;j<q;j++){
      if(S[i]==T[j]){
	t++;
	T[j]=-1;
	break;
      }
    }
  } 
 
  printf("%d\n",t);
  return 0;
}
