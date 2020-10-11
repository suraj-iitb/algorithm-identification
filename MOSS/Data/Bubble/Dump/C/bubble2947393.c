/*昇順のバブルソート*/
#include <stdio.h>
#include <stdlib.h>

int main() {
  int flag=1;
  int flag_count =0;
  int key;
  int judge=0;
  int n;
  int i,j;
  int *array;

  scanf("%d",&n);
  array = (int *)malloc(n * sizeof(int));

  for(i=0;i<n;i++) {
    scanf("%d",array+i);
  }
  while(flag == 1)
    {
      judge=0;
      for(i=n-1;i>0;i--) {
	if(array[i] < array[i-1]) {
	  key = array[i-1];
	  array[i-1] = array[i];
	  array[i] = key;
	  judge=1;
	  flag_count++;
	}
      }
      if(judge==0) {
	flag=0;
      }
    }
  for(i=0;i<n-1;i++) {
    printf("%d ",array[i]);
  }
  printf("%d\n%d\n",array[n-1],flag_count);
  
  return 0;
}
