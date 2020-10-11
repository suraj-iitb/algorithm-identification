#include <stdio.h>

int main(){

  int num[100], i,j,n,f=0,a=0,z,c=0;


  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&num[i]);
  }
  
  for(i=0;i<n-1;i++){
    f=1;
    
    while(f){
      f=0;
      
      for(j=n-1;j>0;j--){
	if(num[j] < num[j-1]){
	  
	  z=num[j];
	  num[j]=num[j-1];
	  num[j-1]=z;
	  c+=1;

	  f=1;
	}
      }
    }
  }

  for(i=0;i<n-1;i++){
    printf("%d ",num[i]);
  }

  printf("%d\n",num[n-1]);
  printf("%d\n",c);
  return 0;
}
	
    


