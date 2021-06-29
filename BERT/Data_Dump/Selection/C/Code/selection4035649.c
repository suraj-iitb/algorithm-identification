#include <stdio.h>

int main()
{
  int i, j, minj, tmp, numdata, swapcount = 0, data[100];

  scanf("%d",&numdata);
  
  for(i = 0; i < numdata; i++) {
    scanf("%d",&data[i]);
  }

  for(i = 0; i <= numdata - 1; i++) {
    minj = i;
    for(j = i; j <= numdata - 1; j++) {
      if(data[j] < data[minj]) {
	minj = j;
      }
    }
    tmp = data[i];
    data[i] = data[minj];
    data[minj] = tmp;
    if(data[i] != data[minj]) swapcount++;
  }

  for(i = 0; i < numdata; i++) {
    if(i) printf(" ");
    printf("%d",data[i]);
  }
  printf("\n%d\n",swapcount);

  return 0;
}

