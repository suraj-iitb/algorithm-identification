#include<stdio.h>
#define A 1000
#define N 100

main(){
  int a,b[A],i,j,v;
  scanf("%d",&a);
  for(j=0;j<a;j++){
    scanf("%d",&b[j]);
  }

  for(i=1;i<a+1;i++){
    for(j=0;j<a-1;j++){
      printf("%d ",b[j]);
    }
    printf("%d",b[a-1]);
    printf("\n");
    v = b[i];
    j = i - 1;
   while(j>=0 && b[j]>v){
     b[j+1] = b[j];
     j--;
     b[j+1] = v;
   }
  }
  return 0;
}
