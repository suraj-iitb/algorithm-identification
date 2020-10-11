#include<stdio.h>

int main(){

  int n,i,j,a[100],b,count=0;

  scanf("%d",&n);

  for(i = 0 ; i < n; i++){
  scanf("%d",&a[i]);
  }

  for(i = n-1; i > 0; i--){
    for(j = n-1; j > 0; j--){

      if(a[j] < a[j-1]){
	b = a[j];
	a[j] = a[j-1];
	a[j-1] = b;
	count++;

      }
    }
  }
    
  for(i = 0 ; i < n; i++){
   

    if(i == n-1){
      printf("%d\n",a[i]);
      printf("%d\n",count);
      break;
    }

     printf("%d ",a[i]);

  }

  return 0;
}

