#include <stdio.h>

void change_s(int a[],int x);

int main()
{
  int x,i;
  int a[100];
  
  scanf("%d",&x);
  if(1<=x&&x<=100){
    for(i=0;i<x;i++) {
      scanf("%d",&a[i]);
    }
    for(i=0;i<x;i++) {
      if(i>0) printf(" "); 
      printf("%d",a[i]);
    }
    printf("\n");
  }

  change_s(a,x);

  return 0;
}

void change_s(int a[],int x) {
  int c,d,i,j;
  for(i=0;i<x;i++) {
    c=a[i];
    if(i==0) continue;
    d=i-1;
    while(d>=0 && a[d]>c) {
      a[d+1]=a[d];
      d--;
      a[d+1]=c;
    }
    for(j=0;j<x;j++) {
      if(j>0) printf(" "); 
      printf("%d",a[j]);
    }
    printf("\n");
  }
}

