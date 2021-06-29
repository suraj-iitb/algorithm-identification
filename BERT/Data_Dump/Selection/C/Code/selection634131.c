#include<stdio.h>
#define A 100
 
int main(){
   
  int b,c,d=0,e,f;
  int a[A];
  int s;
   
  scanf("%d",&e);
   
  for(b = 1;b <= e;b++){
    scanf("%d",&a[b]);
  }
   
   
 
   
  for(b = 1;b <= e;b++){
    s = b;
     
    for(c = b;c <= e;c++)
      if(a[s] > a[c])
    s = c;
     
    if(a[s] < a[b]){
    f = a[b];
    a[b] = a[s];
    a[s] = f;
    d++;
      }
  }
   
  for(b = 1;b <= e;b++){
      if(b == e)
    printf("%d",a[b]);
      else
    printf("%d ",a[b]);
    }
    printf("\n%d\n",d);
    return 0;
     
}
