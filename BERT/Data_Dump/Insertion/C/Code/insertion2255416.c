#include <stdio.h>
#define N 100
int main(){

  int a,b[N],i,d,k,j;

  scanf("%d",&a);
  
  for(i=0;i<a;i++){
    scanf("%d",&b[i]);
  }

  for(j=0;j<a;j++) {
    printf("%d",b[j]);
    if(j<a-1)printf(" ");
  }
  printf("\n"); 
  
for(i=1;i<=a-1;i++){
    d=i;
 
    while(d>0 && b[d]< b[d-1]){
      k=b[d];
      b[d]=b[d-1];
      b[d-1]=k;
      d--;
    }
    for(j=0;j<a;j++) {
      printf("%d",b[j]);
      if(j<a-1)printf(" ");
    }
    printf("\n"); 
  }
 
  
  return 0;
}
