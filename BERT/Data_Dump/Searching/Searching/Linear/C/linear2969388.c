#include <stdio.h>

#define n 10000
#define q 500

int main(){

  int a,b,i,j,status;

  int count = 0;
  
  int S[n],T[q];
  
  scanf("%d",&a);

  for(i=0;i<a;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&b);

  for(i=0;i<b;i++){
    scanf("%d",&T[i]);
    j = 0;
    while(j<a){
      if(S[j] == T[i]){
	count++;
	break;
      }
      j++;
    }
  }

  printf("%d\n",count);



  return 0;
}

