#include<stdio.h>
#include<stdlib.h>
int main(){
  int a,c=0,d=0,min,s,x,i;
  int *b;
  scanf("%d",&a);
  b=(int *)malloc(sizeof(int) * a);
  for(i=0;i<a;i++){
    scanf("%d",&b[i]);
  }
  while(c<a-1){
    min=b[c];
    for(i=c;i<a;i++){
      if(min>b[i]){min=b[i];s=i;}
    }
      if(min<b[c]){x=b[c];b[c]=b[s];b[s]=x;d++;}
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

