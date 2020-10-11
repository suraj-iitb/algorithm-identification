#include<stdio.h>
#include<stdlib.h>
int bubbleSort(int *,int);

int main(){
  int *akira;
  int i,count,n;

  scanf("%d",&n);
  akira=(int *)malloc(sizeof(int)*n);

  for(i=0;i<n;i++){
    scanf("%d",&akira[i]);
  }
  
  count=bubbleSort(akira,n);
  
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",akira[i]);
  }
  printf("\n%d\n",count);
  
  return 0;
}
int bubbleSort(int *akira,int n){
  int i,j,tmp,flag=1,count=0;

  while(flag!=0){
    flag=0;
    for(i=n-1;i>0;i--){
      if(akira[i]<akira[i-1]){
	tmp=akira[i];
	akira[i]=akira[i-1];
	akira[i-1]=tmp;
	count++;
	flag=1;
      }
    }
  }
  return count;
}

