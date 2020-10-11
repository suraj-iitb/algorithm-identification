#include<stdio.h>
#include<stdlib.h>

int main(){
  int i;
  int j;
  int change;
  int num = 0;
  int count = 0;
  int flag = 1;
  int *data;

scanf("%d",&num);
data = (int *)malloc(sizeof(int)*num);

for(j = 0;j < num;j++){
  scanf("%d",&data[j]);
}

  while(flag){
    flag = 0;

for(i = num - 1;i > 0;i--){
  if(data[i] < data[i - 1]){
    change = data[i];
    data[i] = data[i - 1];
    data[i - 1] = change;
    flag = 1;
    count++;
  }
  }
}

for(i = 0;i < num-1;i++){
  printf("%d ",data[i]);
}
printf("%d",data[num - 1]);
printf("\n");
printf("%d",count);
printf("\n");
return 0;
}

