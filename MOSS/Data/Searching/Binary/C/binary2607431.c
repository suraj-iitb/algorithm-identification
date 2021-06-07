#include <stdio.h>

int main(){

  int n,q,i,key,a,b,X;

  int S[100000],ans = 0;

  scanf("%d" ,&n);

  for(i = 0 ; i < n ; i++){
   
   scanf("%d" , S + i);

  }

  scanf("%d" ,&q);

  for(i = 0 ; i < q ; i++){

    scanf("%d" ,&key);
    a = 0; b = n;
    
     while(b >= a){
     
      X = (a + b) / 2;

      if(S[X] == key){
    ans++;
    break;
  
     }

    if(S[X] < key){
     a = X+1;
    }else{

     b = X-1;
      }
    }
   }
   
  printf("%d\n" ,ans);

  return 0;
}
