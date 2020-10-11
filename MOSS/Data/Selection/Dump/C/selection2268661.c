#include <stdio.h>
int main(){
  int i, j, tmp, num[100], k, minj, x=0;

  scanf("%d", &k);
  for(i=0; i < k; i++)
    {
      scanf("%d", &num[i]);
    }

  for(i=0; i<k; i++){
    minj = i;
    for(j=i; j<k; j++){
      if(num[j] < num[minj]){
	minj = j;
      }
    }
    tmp = num[i];
    num[i] = num[minj];
    num[minj] = tmp;
    
    if(minj != i){
      x++;
    }
  }
  
  for(i=0; i<k; ++i)
    {
      printf("%d", num[i]);
      if(i+1>=k) break;
      printf(" ");
    }
  printf("\n%d\n", x);
  
  return 0;
}
