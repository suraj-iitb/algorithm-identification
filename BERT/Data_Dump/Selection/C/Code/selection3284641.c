#include<stdio.h>

int main(){

  int i,m,j,minj;
  int ba[100];
  int flag;
  int cnt = 0;
  int c = 0;
  int k;
  int ak = 0;
  

  scanf("%d",&i);

  for(m = 0; m < i; m++){
    scanf("%d",&ba[m]);
  }


  for(k = 0; k < i; k++){
    minj = k;
    for(j = k; j < i; j++){
      if(ba[j] < ba[minj]){
	minj = j;
      }
    }
      if(ba[k] != ba[minj]){
	ak = ba[k];
	ba[k] = ba[minj];
	ba[minj] = ak;
	cnt++;
      }
    
  }
  

 
   for(c = 0; c < i; c++){
     printf("%d",ba[c]);
     if(c != i-1){
       printf(" ");
   }
  }
   printf("\n%d\n",cnt);

   return 0;
}

