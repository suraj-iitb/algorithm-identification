/*昇順の選択ソート*/
#include <stdio.h>
#include <stdlib.h>

int main() {
  int flag=1;
  int flag_count =0;
  int key;
  int judge=0;
  int n;
  int i,j=0;
  int *array;
  int min;

  scanf("%d",&n);
  array = (int *)malloc(n * sizeof(int));

  for(i=0;i<n;i++) {
    scanf("%d",array+i);
  }
  while(1)
    {
      if(j == n-1) break;
      min = j+1;
      for(i = j;i<n;i++) {
	if(array[i] < array[min]) {
	  min = i;
	}
      }
      if(array[j] > array[min]) {
       key = array[min];
       array[min] = array[j];
       array[j] = key;
       flag_count++;
      }
      j++;
    }
  for(i=0;i<n-1;i++) {
    printf("%d ",array[i]);
  }
  printf("%d\n%d\n",array[n-1],flag_count);
  
  return 0;
}

