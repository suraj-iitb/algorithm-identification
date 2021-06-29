#include<stdio.h>


int main(){
  int a[1000];
  int i,j,v,n,k;
  
  scanf("%d",&n);
  
  if(n>=1&&n<=100){
    
    for(i=0;i<n;i++){
      scanf("%d",&a[i]);
    }
    for(k=0;k<n;k++){
      printf("%d",a[k]);
      if(k<n-1)printf(" ");
    }
    printf("\n");
    
    for(i=1;i<=n-1;i++){
      v=a[i];
      j=i-1;
      
      while(j>=0&&a[j]>v){
	a[j+1]=a[j];
	j--;
	a[j+1]=v;
      }
      
      for(k=0;k<n;k++){
	printf("%d",a[k]);
	if(k<n-1)printf(" ");
      }
      printf("\n");
      
    }
  }
}

