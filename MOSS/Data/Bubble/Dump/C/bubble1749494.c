
#include<stdio.h>

int main(){
  int N,num[100];
  int i,j=0,flag,res,count=0;

  scanf("%d",&N);
  
  
  for(i=0;i<N;++i){
    scanf("%d",&num[i]);
  }

  while(j!=N){
    flag=1;

    while(flag){
    flag=0;

  for(i=N-1;i>0;--i){
    if(num[i]<num[i-1]){
      res=num[i];
      num[i]=num[i-1];
      num[i-1]=res;
      ++count;
      flag=1;
    }
  }
    }
  ++j;
  }

  for(i=0;i<N;i++){
    printf("%d",num[i]);
    if(i!=N-1) printf(" ");
    else printf("\n");
  }

  printf("%d\n",count);

  return 0;
}
