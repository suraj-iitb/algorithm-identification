#include <stdio.h>
#include <stdlib.h>
int main(){
  int n, cnt = 0, i, j;
  scanf("%d", &n);
  int *dat;
  dat = (int *)malloc(sizeof(int) * n);
  for(i = 0; i < n; i++)
    scanf("%d", &dat[i]);
  for(i = 0; i < n - 1; i++)
    for(j = n - 1; j > i; j--)
      if(dat[j - 1] > dat[j]){
	int tmp = dat[j - 1];
	dat[j - 1] = dat[j];
	dat[j] = tmp;
	cnt++;
      }
  printf("%d", dat[0]);
  for(i = 1; i < n; i++)
    printf(" %d", dat[i]);
  printf("\n%d\n", cnt);
  return 0;
}
