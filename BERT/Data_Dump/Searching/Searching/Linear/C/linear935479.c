#include <stdio.h>
#define n 10000
#define q 500

int main(){
 
 int i,j,count=0;
  int S[n],T[q];
  int Ain,Bin;
  
  scanf("%d",&Ain);  
  for(i=0;i<Ain;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&Bin);
  for(i=0;i<Bin;i++){
    scanf("%d",&T[i]);
  }
  
  for(i=0;i<Bin;i++){
    for(j=0;j<Ain;j++){
      if(T[i]==S[j]){
	count++;
	break;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}
