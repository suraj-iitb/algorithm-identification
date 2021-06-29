#include <stdio.h>

int main(){
  int element,i,j,minj,key,cnt=0;
  int arr[100];
  scanf("%d",&element);
  for(i=0;i<element;i++){
    scanf("%d",&arr[i]);
  }

  for(i=0;i<element;i++){
    minj=i;
    for(j=i;j<element;j++){
      if(arr[j]<arr[minj]){
        minj=j;
      }
    }
    if(arr[i]!=arr[minj])cnt++;
    key=arr[i];
    arr[i]=arr[minj];
    arr[minj]=key;
  }

  for(i=0;i<element-1;i++){
    printf("%d ",arr[i]);
  }
  printf("%d\n",arr[element-1]);
  printf("%d\n",cnt);
  return 0;
}
