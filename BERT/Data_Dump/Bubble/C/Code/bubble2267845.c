#include <stdio.h>
int main(){
  int n,i,j,flag=1,a[100],swap,c=0;

  scanf("%d",&n);
  for( i = 0; i < n; i++){
    scanf("%d",&a[i]);
  }

  while(flag){
    flag = 0;
    for(j = n-1; j > 0; j--){ 
	if(a[j] < a[j-1]){
	  
	  swap = a[j-1];
	  a[j-1] = a[j];
	  a[j] = swap;
	  c++;
	  flag = 1;
	}
      }

      
    }
    for( j = 0; j < n-1; j++){
      printf("%d ",a[j]);
    }
    printf("%d\n%d\n",a[n-1],c);
    
    return 0;
}

  
