#include <stdio.h>
#include <stdlib.h>
#define N 100
int bubbleSort(int *,int);

int main(){
  int i,num=0,num2[N],new;
  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&num2[i]);
  }
  new=bubbleSort(num2,num);
  for(i=0;i<num;i++){
    if(i<num-1) printf("%d ",num2[i]);
    else printf("%d\n",num2[i]);
  }
  printf("%d\n",new);
  return 0;
}

int bubbleSort(int *num2,int num){
  int i,flag=1,j=0,temp=0,cnt=0;
  while(flag){
    flag=0;
    for(i=num-1;i>=j+1;i--){
      if(num2[i]<num2[i-1]){
	flag=1;
	temp=num2[i];
	num2[i]=num2[i-1];
	num2[i-1]=temp;
	cnt++;
      }
    }
    j++;
  }
  return cnt;
}
