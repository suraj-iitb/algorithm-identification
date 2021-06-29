#include<stdio.h>
#define N 100


int main(){
  int Sec[N],num,i,j,count=0;
  int temp=0,min=0;

  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&Sec[i]);
  }

  for(i=0;i<num-1;i++){
    min=i;
    for(j=i;j<num;j++){
      if(Sec[j]<Sec[min]){
	min=j;
      }
    }
    temp=Sec[i];
    Sec[i]=Sec[min];
    Sec[min]=temp;
    if(i!=min)count++;
  }
  
  for(i=0;i<num-1;i++){
    printf("%d ",Sec[i]);
  }

  printf("%d\n%d\n",Sec[num-1],count);
  return 0;
}

