#include <stdio.h>

int main(){

  int ori,n,j,i,a[1000],l,key;

  scanf("%d",&n); 

  for(i=0;i<n;i++){
    scanf("%d",&ori);
    a[i]=ori;
  }

  for(l=0;l<n-1;l++){
    printf("%d ",a[l]);
  }
  printf("%d\n",a[l]);
   
  for(j=1;j<n;j++){
    key=a[j];
    i=j-1;
    
    while(i>=0 && a[i]>key){
      a[i+1]=a[i];
      i--;
    }
      a[i+1]=key;

      for(l=0;l<n-1;l++){
	printf("%d ",a[l]);
      }
      printf("%d\n",a[l]);  
  }
 
  return 0;
}


    

