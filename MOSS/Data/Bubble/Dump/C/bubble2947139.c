#include<stdio.h>
#define N 100

int main(){
  int num,i,j,temp=0;
  int Bubble[N];
  int count=0,flag=0;
  

  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&Bubble[i]);
  }

  flag=1;
  while(flag){
    flag=0;
    for(j=num-1;j>0;j--){
      if(Bubble[j]<Bubble[j-1]){
	temp=Bubble[j];
	Bubble[j]=Bubble[j-1];
	Bubble[j-1]=temp;
	count++;
	flag=1;
      }
    }
  }
  
  for(i=0;i<num-1;i++){
    printf("%d ",Bubble[i]);
  }
  
  printf("%d\n%d\n",Bubble[num-1],count);
  return 0;
}

