#include<stdio.h>

int main(){

  int i,m,j;
  int b[100];
  int flg;
  int cnt = 0;
  int c = 0;
  int k;
  int a = 0;

  scanf("%d",&i);

  for(m = 0; m < i; m++){
    scanf("%d",&b[m]);
  }

  flg = 1;
  
  for(k = 0; k < i; k++){
      
  while(flg){
      
       flg = 0;
       for( j =i-1; j >= k+1; j--){
	 if( b[j] < b[j-1]){
	   a = b[j];
	   b[j] = b[j-1];
	   b[j-1] = a;
	   cnt++;
	   flg = 1;
	 }
       }
     }
  }

 
   for(c = 0; c < i; c++){
     printf("%d",b[c]);
     if(c != i-1){
       printf(" ");
   }
  }
   printf("\n%d\n",cnt);

   return 0;
}


