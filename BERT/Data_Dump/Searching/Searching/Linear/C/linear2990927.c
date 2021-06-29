#include <stdio.h>
int main(){
  int i,j,a,b,c1=0,c2=0;
  int hai1[10000],hai2[1000];

  scanf("%d",&a);
  for(i=0;i < a ; i++){
    scanf("%d",&hai1[i]);
  }
  scanf("%d",&b);
  for(i=0;i < b ; i++){
    scanf("%d",&hai2[i]);
  }
 
  
  for(i=0 ;i < b ; i++){
    for(j=0 ; j  < a ; j++){
      if(hai1[j] == hai2[i]){
        c2++;
        c1++;
        if(c2>=2){
          c1--;
        }
      }
    }
    c2=0;
  }
  printf("%d",c1);
  printf("\n");

  return 0;
}

