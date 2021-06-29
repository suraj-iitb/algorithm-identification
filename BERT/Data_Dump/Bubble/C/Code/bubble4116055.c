#include <stdio.h>

void sort(int n,int data[]){
  int flag = 0;
  int counter = 0;
  int tmp;
  while (1==1){
    flag = 0;
    for (int i = 0; i < n-1; i ++ ){
      if (data[i] > data[i+1]){
        counter += 1;
        tmp = data[i];
        data[i] = data[i+1];
        data[i+1] = tmp;
        flag = 1;
      }
    }
    if (flag == 0){
      for (int i = 0; i < n ; i ++){
        if ( i > 0 ) printf(" ");
        printf("%d",data[i]);
      }
      printf("\n");
      printf("%d\n",counter);
      break;
      
    }
  }
}

int main(void){
  //入出力処理
  int n,data[100];
  scanf("%d",&n);
  for (int i = 0; i < n ; i ++ ){
    scanf("%d",&data[i]);
  }
  sort(n,data);
  return 0;
}



