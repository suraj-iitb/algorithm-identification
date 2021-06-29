#include<stdio.h>

int search(int *,int,int);

int main(){
  int S_num[10000];
  int T_num;
  int i;
  int num_in_1;
  int num_in_2;
  int key;
  int count=0;

  scanf("%d",&num_in_1);

  for(i=0;i<num_in_1;i++){
    scanf("%d",&S_num[i]);
  }
 
  scanf("%d",&num_in_2);
  
  for(i=0;i<num_in_2;i++){
    scanf("%d",&key);
    if(search(S_num,num_in_1,key)==1){
      count++;
    }
  }

  printf("%d\n",count);
  return 0;
}

int search(int S_num[],int num_in,int key){
  int i=0;

  S_num[num_in]=key;

  while(S_num[i]!=key){
    i++;
  }

  if(i==num_in){
    return 0;
  }else{
    return 1;
  }
}
