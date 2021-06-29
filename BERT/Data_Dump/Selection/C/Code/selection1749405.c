#include <stdio.h>
#include <stdlib.h>
int main(){
  int n, cnt = 0, i, j;
  scanf("%d", &n);
  int *dat;
  dat = (int *)malloc(sizeof(int) * n);
  for(i = 0; i < n; i++)
    scanf("%d", &dat[i]);
  for(i = 0; i < n - 1; i++){
    int jmin = i;
    for(j = i + 1; j < n; j++){
      if(dat[j] < dat[jmin])
	jmin = j;
    }
    if(jmin != i){
      int tmp = dat[i];
      dat[i] = dat[jmin];
      dat[jmin] = tmp;
      cnt++;
    }
  }
  printf("%d", dat[0]);
  for(i = 1; i < n; i++)
    printf(" %d", dat[i]);
  printf("\n%d\n", cnt);
  return 0;
}
