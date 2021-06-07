#include<stdio.h>
int main(){

  int a[10000],b[10000],i,j,x,y,count=0;

  scanf("%d",&x);
  for(i=0;i<x;i++){
    scanf("%d",&a[i]);
    }

  scanf("%d",&y);
  for(i=0;i<y;i++){
    scanf("%d",&b[i]);
  }

  for(i=0;i<y;i++){
    for(j=0;j<x;j++){
      if(a[j]==b[i]){
	count++;
	break;
      }
    }
  }

  printf("%d\n",count);
	
      
      
      


    return 0;
    }
    
      

