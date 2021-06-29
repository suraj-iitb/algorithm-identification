#include<stdio.h>

int main(){
  int i,j,n,b,k;
  scanf("%d",&n);
  int a[n];
  for(k=0;k<n;k++){
    scanf("%d",&a[k]);
  }
  for(k=0;k<n;k++){
      if(k==n-1){
      printf("%d\n",a[k]);
      }else{
	
    printf("%d ",a[k]);
      
  }
  }
  
  for(i=1;i<=n-1;i++){
    b=a[i];
    j=i-1;
    while(j>=0 && a[j]>b){
      a[j+1]=a[j];
      j--;
      a[j+1]=b;
    }
    
    for(k=0;k<n;k++){
      if(k==n-1){
      printf("%d\n",a[k]);
      }else{
	
    printf("%d ",a[k]);
      
  }
    }
  }
  return 0;
}

