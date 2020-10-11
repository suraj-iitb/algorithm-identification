#include <stdio.h>
int main()
{
  int num,arr[100],tmp,flag,cnt = 0,i;
  scanf("%d",&num);
  for(int i = 0; i < num; i++){
    scanf("%d",&arr[i]);
  }
  flag = 1;
  i = 0;
  while(flag ==1){
    flag = 0;
    for(int j = num - 1; j > 0; j--){
      if(arr[j] < arr[j-1]){
	tmp = arr[j];
	arr[j] = arr[j-1];
	arr[j-1] = tmp;
	cnt++;
	flag = 1;
      }
    }
    i++;
  }
  for(int i = 0; i < num -1; i++){
    printf("%d ",arr[i]);
  }
  printf("%d\n%d\n",arr[num - 1],cnt);
  return 0;
}
