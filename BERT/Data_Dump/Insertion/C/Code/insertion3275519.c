#include<stdio.h>

int main(){
  int i,j,k,n,key;
  int a[1000];
  
  scanf("%d",&n);
  
  for (i=0;i<n;i++){
    scanf("%d",&a[i]);
  }


  for(i=0;i<n;i++){
      printf("%d",a[i]);
      if(i!=n-1) printf(" ");
    }

    printf("\n");
  for(i=1;i<=n-1;i++){
    key=a[i];
    j=i-1;
    
    while(j >= 0 && a[j] > key){
      a[j+1]=a[j];
      j--;
      
    }
    
    a[j+1]=key;

    for(k=0;k<n;k++){
      printf("%d",a[k]);
      if(k!=n-1) printf(" ");
    }

    printf("\n");
    
  }
  
  return 0;
  
}

