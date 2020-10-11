#include<stdio.h>

int main(){
  int n,i,j,flag=1,w,c=0;
  int a[100];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<n;i++){
    
    while(flag){
      flag=0;
    
      for(j=n-1;j>=i+1;j--){
      
        if(a[j]<a[j-1]){
	  w=a[j];
	  a[j]=a[j-1];
	  a[j-1]=w;
	  flag=1;
	  c++;
        }
	
      } 
 
    }
    
  }
  
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1) printf(" ");
  }
  
  printf("\n%d\n",c);

  return 0;
}

