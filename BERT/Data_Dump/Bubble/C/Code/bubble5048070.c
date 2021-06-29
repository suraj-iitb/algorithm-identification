#include <stdio.h>

int main(){
  int element,i,key,flag,cnt=0;
  int arr[100];
  scanf("%d",&element);
  for(i=0;i<element;i++){
    scanf("%d",&arr[i]);
  }

  flag=1;
  while(flag){
    flag = 0;
    for(i=element-1;i>0;i--){
      if(arr[i]<arr[i-1]){
        key = arr[i];
        arr[i]=arr[i-1];
        arr[i-1]=key;
        flag=1;
        cnt++;
      }
    }
  }

  for(i=0;i<element-1;i++){
    printf("%d ",arr[i]);
  }
  printf("%d\n",arr[element-1]);
  printf("%d\n",cnt);
  return 0;
}
