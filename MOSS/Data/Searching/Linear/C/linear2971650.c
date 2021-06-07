#include <stdio.h>

int main(){
  int n,q;
  int i,j;
  int S[10000],T[10000];
  int awcount=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
 
    for(j=0;j<n;j++){
      if(T[i]==S[j]){
	awcount++;
	T[i]=-1;
      }
    }
  }
  
  printf("%d\n",awcount);

  return 0;
}
  

  

