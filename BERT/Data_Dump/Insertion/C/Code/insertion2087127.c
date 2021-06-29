#include <stdio.h>

#define MAX 1001


int main(){

  int n;
  scanf("%d%*c", &n);

  int a[MAX], b[MAX];
  int i,j,k;
  for(i = 0; i < n; i++){
    scanf("%d%*c", &a[i]);
  }

  for(i = 0; i < n; i++){
    b[i] = a[i];
  }

  for(k = 0; k < n-1; k++){
    printf("%d ", b[k]);
  }
  printf("%d\n", b[n-1]);
  
  for(i = 1; i < n; i++){
    for(j = 0; j < i; j++){
      if(b[j] > a[i]){

	for(k = i; k > j; k--){
	  b[k] = b[k-1];
	}
	b[j] = a[i];
	break;
      }	
    }

    for(k = 0; k < n-1; k++){
      printf("%d ", b[k]);
    }
    printf("%d\n", b[n-1]);
  }
  
  return 0;
}
