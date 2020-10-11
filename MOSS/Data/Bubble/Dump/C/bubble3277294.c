#include<stdio.h>

int main(){

  int i,m,j;
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

  flag = 1;
  for(k = 0; k < i; k++){
  while(flag){
       flag = 0;
       for( j =i-1; j >= k+1; j--){
	 if( ba[j] < ba[j-1]){
	   ak = ba[j];
	   ba[j] = ba[j-1];
	   ba[j-1] = ak;
	   cnt++;
	   flag = 1;
	 }
       }
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

