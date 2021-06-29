#include <stdio.h>
int main(){

  int i,j,n,tmp,min,cnt = 0;

  int arr[100];

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++)scanf("%d",&arr[i]);

  for(i = 0 ; i < n ; i ++){

    min = i;

    for(j = i ; j < n ; j++)if(arr[min] > arr[j])min = j;//最小値の添字を検索

    if(i != min){
      tmp = arr[min];
      arr[min] = arr[i];
      arr[i] = tmp;
      cnt++;
    }
  }

  for(i = 0 ; i < n-1 ; i++)printf("%d ",arr[i]);

  printf("%d\n",arr[i]);
  printf("%d\n",cnt);
  return 0;
}
