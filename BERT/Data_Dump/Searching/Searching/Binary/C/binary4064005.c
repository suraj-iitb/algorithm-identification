#include<stdio.h>

int A[1000000];
int n;

int binarySearch(int key){
  
  int left = 0;
  int right = n;
  int mid;
  
 while(left < right){
    mid = (left + right) / 2;
	  if(key == A[mid])return 1;
	  else if(key < A[mid]) right = mid;
        else left = mid + 1;
  }
  return 0;
}

  int main(){
    int i, x, y, sum = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
     scanf("%d", &A[i]);
    }

    scanf("%d", &x);
    for(i = 0; i < x; i++){
      scanf("%d", &y);
      if(binarySearch(y))sum++;
      else continue;}
    
      printf("%d\n", sum);
      return 0;
  }

