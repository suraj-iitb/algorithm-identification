#include<stdio.h>
int main(){

  int a[100000],b[50000],i,j,x,y,count=0,left,right,mid;

  scanf("%d",&x);
  for(i=0;i<x;i++){
    scanf("%d",&a[i]);
    }

  scanf("%d",&y);
  for(i=0;i<y;i++){
    scanf("%d",&b[i]);
  }


  for(i=0;i<y;i++){
    left=0;
    right=x;
    while(left<right){
      mid=(left+right)/2;
      if(a[mid]==b[i]){
	count++;
	break;
      }
	else if(b[i]<a[mid]){
	  right=mid;
	}
	  else left=mid+1;
	}
      }
    
  
	
	printf("%d\n",count);
	
      return 0;
    }
    
      

