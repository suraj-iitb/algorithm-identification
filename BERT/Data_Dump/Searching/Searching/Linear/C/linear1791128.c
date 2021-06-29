#include <stdio.h>

#define SMAX 10000
#define TMAX 500

int main(){

  int i, j, count, snum, tnum, key;
  
  int sdata[SMAX];
  int tdata[TMAX];

  count = 0;

  scanf("%d", &snum);

  for(i = 0; i < snum; i++){

    scanf("%d", &sdata[i]);

  }

  
  scanf("%d", &tnum);

  for(i = 0; i < tnum; i++){

    scanf("%d", &tdata[i]);

  }

  for(i = 0; i < tnum; i++){

    for(j = 0; j < snum; j++){

      if(tdata[i] == sdata[j]){

	count++;
	break;

      }

    }    

  }
  
  printf("%d\n", count);

  return 0;

}
