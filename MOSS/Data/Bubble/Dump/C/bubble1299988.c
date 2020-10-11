#include<stdio.h>
#include<stdlib.h>
#define N 100

int main(){

  int a[N];
  int i,j,len,c,count=0;

  scanf("%d",&len);
  if(len>N)exit(8);
  for(i = 0; i < len; i++){
    scanf("%d",&a[i]);
  }

  for(i = 0; i < len; i++){
    for(j = len -1; i < j; j--){
      if(a[j] < a[j-1]){
	c = a[j];
	a[j] = a[j-1];
	a[j-1] = c;
	count++;
      }
    }
  }
      for(i = 0; i < len; i++){
	if(i == len-1)printf("%d",a[i]);
	else {
	  printf("%d",a[i]);
	  printf(" ");
	}
      }
      
      printf("\n");
      printf("%d\n",count);

      return 0;
  }
