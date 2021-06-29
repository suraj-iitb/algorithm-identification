#include <stdio.h>
int main()
{
  int num,arr[100],i,minj,tmp,cnt=0;
  scanf("%d",&num);
  for(i = 0; i < num; i++){
    scanf("%d",&arr[i]);
  }
  for( i = 0; i < num; i++){
    minj = i;
    for(int j = i; j < num; j++){
      if(arr[j] < arr[minj]) minj =j;
    }
      if(arr[i] != arr[minj]){
	tmp = arr[i];
	arr[i] = arr[minj];
	arr[minj] = tmp;
	cnt++;
      }
  }
  for(i = 0; i < num - 1; i++){
    printf("%d ",arr[i]);
  }
  printf("%d\n%d\n",arr[num - 1],cnt);
  return 0;
}

