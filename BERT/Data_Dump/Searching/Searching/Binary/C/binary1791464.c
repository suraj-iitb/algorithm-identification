#include <stdio.h>

#define SMAX 100000
#define TMAX 50000

int main(){

  int i, j, temp, count, snum, tnum, left, right, mid;
  
  int sdata[SMAX];
  int tdata[TMAX];

  count = 0;
  

  //入力
  scanf("%d", &snum);

  for(i = 0; i < snum; i++){

    scanf("%d", &sdata[i]);

  }
 
  scanf("%d", &tnum);

  for(i = 0; i < tnum; i++){

    scanf("%d", &tdata[i]);

  }

  //検索
  for(i = 0; i < tnum; i++){

    left = 0;
    
    right = snum;

    while(left < right){

      mid = ((left + right) / 2);

      if(tdata[i] == sdata[mid]){

	count++;
	break;

      }

      else if(tdata[i] > sdata[mid]){

	left = mid + 1;

	while(sdata[left] == sdata[left + 1]){
	  
	  left++;

	}

      }

      else{

	right = mid;

	while(sdata[right] == sdata[right -1]){
	  
	  right--;
  
	}

      }

    }

  }
  
  printf("%d\n", count);

  return 0;

}
