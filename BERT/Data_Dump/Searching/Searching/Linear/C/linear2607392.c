#include<stdio.h>

int main()
{
  int n, m, S[10000], T[500], i, j, count;
  count = 0;
  
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }
  
  scanf("%d", &m);
  for(i = 0; i < m; i++){
    scanf("%d", &T[i]);
  }
  
  for(i = 0; i < n; i++){
    for(j = i+1; j < n; j++){
      if(S[i] == S[j]){
        S[j] = -1;
      }
    }
  }
  
  for(i = 0; i < m; i++){
    for(j = 0; j < n; j++){
      if(T[i] == S[j]){
        count++;
      }
    }
  }
  
  printf("%d\n", count);
}
