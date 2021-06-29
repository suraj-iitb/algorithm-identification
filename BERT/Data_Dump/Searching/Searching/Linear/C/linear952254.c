#include <stdio.h>
#define N 10000
#define Q 500
 
int main(){
  
  int i,j,c=0,n,q;
  int S[N],T[Q];
   
  scanf("%d",&n);  
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
   
  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(T[i]==S[j]){ //n>q
	c++;
	break;
      }
    }
  }
  printf("%d\n",c);
  return 0;
}
