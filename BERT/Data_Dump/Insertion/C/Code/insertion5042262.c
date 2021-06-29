#include  <stdio.h>
#define  N 100

int main(){
  int i, j;
  int n;
  int key;
  int Array[N];
    
  scanf("%d", &n);
  
  for(i = 0; i < n; i++) scanf("%d", &Array[i]);
  
  for(j = 1; j <= n-1; j++){

    for(i = 0; i < n-1; i++) printf("%d ", Array[i]);
    printf("%d\n", Array[i]);
    
    key = Array[j];
    i = j - 1;
    
    while(i >= 0 && key < Array[i]){
      Array[i+1] = Array[i];
      i--;
    }
    
    Array[i+1] = key;
  }

  for(i = 0; i < n-1; i++) printf("%d ", Array[i]);
  printf("%d\n", Array[i]);
  
  return 0;
}

