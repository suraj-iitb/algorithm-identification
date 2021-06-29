#include<stdio.h>
int main(void){

  int a,b[100],i,j,n=0,x,y,z;
  scanf("%d",&a);

  for(i=0;i<a;i++){
    scanf("%d",&b[i]);
  }

  for(i=0;i<a-1;i++){
    z = i; 
    x = b[i];
    for(j=i;j<a;j++){
       
      if(b[j]<x){
    x = b[j];
    z = j;
      }
    }

    if(x!=b[i]){
      y = b[i];
      b[i] = b[z];
      b[z] = y;
      n++;
    }
  }

  for(i=0;i<a-1;i++){
    printf("%d ",b[i]);
  }

  printf("%d\n",b[i]);
  printf("%d\n",n);

  return 0;

}
