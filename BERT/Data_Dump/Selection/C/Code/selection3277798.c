#include<stdio.h>
#define N 100

int main(){
  int min,i,j,n,a[N],swap,y=0;

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&a[i]);
    
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){      
      if(a[j]<a[min]){
	min=j;	
      }      
    }
          
    if(min!=i){
      swap=a[i];
      a[i]=a[min];
      a[min]=swap;
      y++;      
    }
    
  }
   
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1) printf(" ");
  }
  
  printf("\n%d\n",y);
  return 0;
}
      

