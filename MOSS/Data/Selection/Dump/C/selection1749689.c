#include<stdio.h>

int main(){
  int N,num[100];
  int i,j,res,min,count=0;

  scanf("%d",&N);
  
  
  for(i=0;i<N;i++){
    scanf("%d",&num[i]);
  }

  for(i=0;i<=N-1;i++){
    min=i;
    for(j=i;j<=N-1;j++){
      if(num[j]<num[min]){
	min=j;
      }
    }
      
      if(num[i]!=num[min]){ 
	res=num[i];
	num[i]=num[min];
	num[min]=res;
	count++;
      }
    }

  for(i=0;i<N;i++){
    printf("%d",num[i]);
    if(i!=N-1) printf(" ");
    else printf("\n");
  }

  printf("%d\n",count);

  return 0;
}
