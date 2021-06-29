#include<stdio.h>
#define A 100
 
int main(){
 
  int b,c,d=0,e,f;
  int a[A];
 
  scanf("%d",&e);
 
  for(b=0;b<e;b++){
    scanf("%d",&a[b]);
  }
 
  for(b=0;b<e;b++){
    for(c=e-1;c>b;c--){
      if(a[c]<a[c-1]){
    f=a[c];
    a[c]=a[c-1];
    a[c-1]=f;
    d++;
      }
    }
  }
 
  for(c=0;c<e;c++){
    if(c==e-1)
      printf("%d",a[c]);
    else
      printf("%d ",a[c]);
  }
  printf("\n%d\n",d);
  return 0;
}
