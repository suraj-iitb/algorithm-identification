#include<stdio.h>
#include<stdlib.h>

int main(void){
  int *num;
  int i,j,v,k,n;
  scanf("%d",&n);
  num=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&num[i]);
  }
  for(k=0;k<n;k++){
	if(k==n-1){
	  printf("%d\n",num[k]);
	}
	else {
	  printf("%d ",num[k]);
	    }
      }
  for(i=1;i<n;i++){
    j=i-1;
    v=num[i];
    while(j>=0 && num[j]>v){
      num[j+1]=num[j];
      j--;
      
    }
    num[j+1]=v;
    for(k=0;k<n;k++){
	if(k==n-1){
	  printf("%d\n",num[k]);
	}
	else {
	  printf("%d ",num[k]);
	    }
      }
  }

  
  
  free(num);
  
  return 0;
}
