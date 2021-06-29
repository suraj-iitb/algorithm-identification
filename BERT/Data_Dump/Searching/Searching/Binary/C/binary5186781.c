#include <stdio.h>

int X[1000000],num;

int binarySearch(int bn){
  int L = 0,R = num,M;

  while(L< R){
    M = (L + R) /2;
    if(bn == X[M]) {
      return 1;
    }
    if(bn > X[M]) {
      L = M +1;
    }
    else if(bn < X[M]) {
      R = M;
    }
  }
    return 0;
  }

    int main(){
      int i,num2,bn,S=0;

      scanf("%d",&num);
      for(i=0;i<num;i++){
 scanf("%d",&X[i]);
      }

      scanf("%d",&num2);
      for(i=0;i<num2;i++){
 scanf("%d",&bn);
 if(binarySearch(bn)){
   S++;
 }
      }
 printf("%d\n",S);

 return 0;
      }

