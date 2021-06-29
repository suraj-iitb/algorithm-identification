#include<stdio.h>
#define A 100
int main(){

  int n,a[A],i,flag,count=0,change;

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&a[i]);
  }
  
  flag = 1;
  while(flag){
      flag = 0;
      for(i = n-1;i > 0;i--){
	if(a[i] < a[i-1]){
	  change = a[i-1];
	  a[i-1] = a[i];
	  a[i] = change;
	  count++;
	  flag = 1;
	}
      }
    }
      for(i = 0;i < n-1;i++){
	printf("%d ",a[i]);
      }
      printf("%d\n%d\n",a[n-1],count);
     
      return 0;
    }
