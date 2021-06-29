#include<stdio.h>

int main(){
  int flag =1;
  int count=0,n,i,j,data[100],temp;
  scanf("%d",&n);
  for(i = 0;i < n;i++){
  scanf("%d",&data[i]);
  }
  while(flag){
    flag = 0;
    for(j = n-1;j > 0;j--){
      if(data[j] < data[j-1]){
        temp = data[j];
        data[j] = data[j-1];
        data[j-1] = temp;
        count++;
        flag= 1;
      }
    }
  }
  for(i = 0;i < n-1;i++)printf("%d ",data[i]);
  printf("%d",data[i]);
  printf("\n%d\n",count);
  return 0;
}

