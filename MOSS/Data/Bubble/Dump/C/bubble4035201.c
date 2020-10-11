#include <stdio.h>

int main() {
  int i, j, numdata, swapcount = 0, data[100], tmp, flag;

  scanf("%d",&numdata);

  for(i = 0; i < numdata; i++) {
    scanf("%d",&data[i]);
  }

  flag = 1;
  i = 0;
  while(flag) {
    flag = 0;
    for(j = numdata - 1; j >= i + 1; j--) {
      if(data[j] < data[j-1]) {
	tmp = data[j];
        data[j] = data[j-1];
	data[j-1] = tmp;
	swapcount++;
	flag = 1;
      }
    }
    i++;
  }

  for(i = 0; i < numdata; i++) {
    if(i) printf(" ");
    printf("%d",data[i]);
  }
  printf("\n%d\n",swapcount);
  
  return 0;
}

