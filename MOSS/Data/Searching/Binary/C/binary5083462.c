#include<stdio.h>

void binary();

int num;
int set[100000000];
int count = 0;

int main(){
  int i;
  int j;
  int Qdata;
  int Time[500000];

  scanf("%d",&num);

  for(i = 0;i < num;i++){
    scanf("%d",&set[i]);
  }

  scanf("%d",&Qdata);

  for(i = 0;i < Qdata;i++){
    scanf("%d",&Time[i]);
    binary(Time[i]);
  }

  printf("%d\n",count);
  return 0;
}

void binary(int data){
  int left = 0;
  int right = num;

  while(left < right){
    int mid = (left + right) / 2;

    if(data == set[mid]){
      count++;
      break;
    }

    else if(data < set[mid]){
      right = mid;
    }

    else{
      left = ++mid;
    }
  }
}

