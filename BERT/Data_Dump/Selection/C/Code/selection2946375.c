#include<stdio.h>
#include<stdlib.h>

int main(){
  int i;
  int j;
  int change = 0;
  int num = 0;
  int count = 0;
  int min = 0;
  int *data;

scanf("%d",&num);
data = (int *)malloc(sizeof(int)*num);

for(j = 0;j < num;j++){
  scanf("%d",&data[j]);
}

for(i = 0;i < num - 1;i++){
  min = i;
  for(j = i;j < num;j++){
    if(data[j] < data[min]){
      min = j;
    }

  }
  if(i != min){
    change = data[i];
    data[i] = data[min];
    data[min] = change;
    count++;
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

