#include<stdio.h>
#include<stdlib.h>
int main(){
  int a,c=0,d=0,x,i;
  int *b;
  scanf("%d",&a);
  b=(int *)malloc(sizeof(int) * a);
  for(i=0;i<a;i++){
    scanf("%d",&b[i]);
  }
  while(c<a-1){
    for(i=a-1;i>0;i--){
      if(b[i]<b[i-1]){x=b[i];b[i]=b[i-1];b[i-1]=x;d++;}
    }
  c++;
  }
  for(i=0;i<a;i++){
  printf("%d",b[i]);
  if(i!=a-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",d);
  return 0;
}
