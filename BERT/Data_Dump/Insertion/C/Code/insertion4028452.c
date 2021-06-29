#include <stdio.h>
int main ()
{
  int num,i,j,key;
  scanf("%d",&num);
  int arr[num];
  for(i = 0; i < num;i++){
  scanf("%d",&arr[i]);
  }
  for(j = 1; j <= num; j++){
    for(int k = 0; k < num - 1; k++){
      printf("%d ",arr[k]);
    }
    printf("%d\n",arr[num - 1]);
    key = arr[j];
    i = j - 1;
    while((i >= 0) && (arr[i] > key)){
      arr[i+1] = arr[i];
      i = i - 1;
    }
    arr[i + 1] = key;
  }
  return 0;
}


