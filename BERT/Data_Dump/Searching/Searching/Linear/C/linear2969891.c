#include <stdio.h>

int linearSearch(int*, int, int);

int main(){
  int N[10000]; int Q[500];
  int nnum, qnum;
  int i, j, search, count = 0;

  scanf("%d", &nnum);
  for(i = 0; i < nnum; i++){
  scanf("%d", &N[i]);
  }
  scanf("%d", &qnum);
  for(i = 0; i < qnum; i++){
  scanf("%d", &Q[i]);
  }
  
  for(i = 0; i < qnum; i++){
    if(linearSearch(N, nnum, Q[i]) == 1){
      count++;
    }
  }
  
  /*
  for(i = 0;i < qnum; i++){
    search = Q[i];
    left = 0;
    right = nnum-1;
    
    while(left < right){
      mid = (left + right)/2;
      if(search == N[mid]){
	printf("%d found\n", search);
	count++;
	break;
      }
      if(search > N[mid]){
	left = mid+1;
      }
      else if(search < N[mid]){
	right = mid;
      }
    }
  }
  */

printf("%d\n", count);
  return 0;
}

int linearSearch(int *A,int length, int key){
  int i = 0;
  
  A[length] = key;
  while( A[i] != key){
    i++;
  }
  if(i == length){
    return 0;
  }
  return 1;
}

