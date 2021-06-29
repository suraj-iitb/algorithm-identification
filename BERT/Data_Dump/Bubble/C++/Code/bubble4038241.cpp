#include<stdio.h>

#define  N 100

int main(){
  int bubble[N];
  int flag;
  int i,j,num,temp,cnt=0;

  scanf("%d",&num);
  for(i=0;i<num;i++) scanf("%d",&bubble[i]);

  flag = 1;
  while(flag == 1){
    flag = 0;
    for(j=num-1;j>0;j--){
      if(bubble[j] < bubble[j-1]){
	//bubble[j]とbubble[j-1]を交換
	temp = bubble[j];
	bubble[j] = bubble[j-1];
	bubble[j-1] = temp;
	flag = 1;
	cnt++;
      }
    }
  }

  for(i=0;i<num;i++){
    if (i) printf(" ");
    printf("%d",bubble[i]);
  }
  
  printf("\n%d\n",cnt);
  
  return 0;
}

