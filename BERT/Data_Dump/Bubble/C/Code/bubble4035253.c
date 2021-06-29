#include <stdio.h>

int main(){

  int n,i,j,change_times=0,x;

  scanf("%d",&n);

  int num[n];

  for(i=0;i<n;i++) scanf("%d",&num[i]);

  for(i=0;i<n;i++){

    for(j=n-1;j>i;j--){

      if(num[j-1]>num[j]){
	
	x=num[j];
	
	num[j]=num[j-1];
	
	num[j-1]=x;

	change_times++;
      }
    }
  }

    for(i=0;i<n;i++){
      
      printf("%d",num[i]);

      if(i<n-1)printf(" ");
    }

    printf("\n%d\n",change_times);

    return 0;
  }

