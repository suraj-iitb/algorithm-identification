#include<stdio.h>
#include<stdlib.h>

int main(void){
  int *num;
  int i,j,k,n;
  int flag=1;
  int box,time=0;
  scanf("%d",&n);
  num=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&num[i]);
  }
  /*sort*/
  while(flag){
    flag=0;
    for(j=n-1;j>=1;j--){
      if(num[j]<num[j-1]){
	box=num[j];
	num[j]=num[j-1];
	num[j-1]=box;
	flag=1;
	time++;
      }
    }

  }
  for(k=0;k<n;k++){
	if(k==n-1){
	  printf("%d\n",num[k]);
	}
	else {
	  printf("%d ",num[k]);
	    }
      }
  printf("%d\n",time);

  
  
  free(num);
  
  return 0;
}
