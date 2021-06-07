#include<stdio.h>
#define N 10000

 main(){
  int i,j,k,l,count=0,a[N],b,c[N],d;
  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&d);
  for(j=0;j<d;j++){
    scanf("%d",&c[j]);
  }

 for(i=0;i<d;i++){
    for(j=0;j<b;j++){
      if(a[j]==c[i]){   
	count++;
	break;
      }
    }
  }
 printf("%d\n",count);
 return 0;
 }
