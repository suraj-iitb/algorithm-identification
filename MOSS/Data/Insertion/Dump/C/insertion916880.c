#include<stdio.h>
main(){
  int a,b,c[100],d,i,j,l;
    scanf("%d",&a);
    for(i = 0; i < a ;i++){
scanf("%d",&c[i]); 
 printf("%d",c[i]);
 if(i != a-1) printf(" ");
} 
 printf("\n");
  for(i = 1; i < a; i++){
    d = c[i];
    j = i -1;
    while(j >= 0 && c[j] > d){
      c[j+1] = c[j];
      j--;
    }
      c[j+1] = d;    
    for(l = 0; l < a ; l++){
printf("%d",c[l]);   
 if(l != a - 1) printf(" ");     
}
    printf("\n");
  }
  return 0;
}
