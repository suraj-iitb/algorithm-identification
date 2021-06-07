#include<stdio.h>
int main()
{
  int j,i,a,b,count=0,mid=0,x=0,y=0,z=0;
  int X[100000],Y[50000],Z[100];
  
  scanf("%d",&a);
  
  for(i=0;i<a;i++){
    scanf("%d",&X[i]);
  }
  
  scanf("%d",&b);
  
  for(i=0;i<b;i++){
    scanf("%d",&Y[i]);
  }
  
  for(i=0;i<b;i++){
    y=0;
    x=a;
    while(y<x){
      mid=(y+x)/2;
      if(X[mid]==Y[i]){
	    count++;
        Z[z]=X[mid];
        z++;
	    break;
      }
      if(Y[i]>X[mid]){
	   y=mid+1;
      }
      else if(Y[i]<X[mid]){
	   x=mid;
      }
    }
  }
  
  printf("%d\n",count);
  
  return 0;
}
