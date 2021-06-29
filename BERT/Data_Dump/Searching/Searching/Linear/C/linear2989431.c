#include<stdio.h>

int main(){
  
  int S[10000], T[500], n, m, i, j, num = 0;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&m);
  
  for(i = 0; i < m; i++){
    scanf("%d",&T[i]);
  }
  for(i = 0; i < m; i++){
    for(j = 0; j < n; j++){  
      if(T[i] == S[j]) {
        num++;
        break;
      }
    }
  }
  printf("%d\n", num);
  return 0;
}

