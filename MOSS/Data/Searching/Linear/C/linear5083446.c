#include<stdio.h>

int senkei();

int main(){
  int i = 0;
  int count2;
  int setdata[10000 + 1];
  int change;
  int key;
  int sum = 0;

  scanf("%d",&count2);

  for(i = 0;i < count2;i++){
    scanf("%d",&setdata[i]);
  }

  scanf("%d",&change);

  for(i = 0;i < change;i++){
    scanf("%d",&key);

    if(senkei(setdata,count2,key)){
      sum++;
    }
  }
  printf("%d",sum);
  printf("\n");
  return 0;
}


int senkei(int data[],int count,int key){
  int i = 0;

  data[count] = key;

  while(data[i] != key){
    i++;
  }
  return i != count;
}

