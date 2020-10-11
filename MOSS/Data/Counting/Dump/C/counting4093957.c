#include <stdio.h>

int main(){
  int i, j, n, getnm, nm, k=0;
  int C[10001];

  for(i = 0; i < 10001; i++){
    C[i] = 0;
  }
 
  scanf("%d", &getnm);

  for(i = 0; i < getnm; i++){
    scanf("%d", &nm);
    C[nm]++;
  }

  for(i = 0; i < 10001; i++){
    for(j = 0; j < C[i]; j++){
      if(k == getnm-1) printf("%d\n", i);
      else {
	printf("%d ", i);
	k++;
      }
    }
  }
  
  return 0;
}

