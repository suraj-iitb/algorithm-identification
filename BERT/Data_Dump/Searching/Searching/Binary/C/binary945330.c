#include <stdio.h>
int main(){

  int n,m,i,a[100000],b[50000],k,j,x,y,z;
  m=0;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&k);
  for(i=0;i<k;i++){
    scanf("%d",&b[i]);
    x=n;
    y=0;
    while(x>y){
      z=(x+y)/2; 
      if(a[z]==b[i]){
	m++;
	break;
      }   
      if(a[z]>b[i]){
	x=z;
      }
      else if(a[z]<b[i]){
	y=z+1;
      }
      
    }
    
  }
  printf("%d\n",m);
  return 0;
}
