#include <stdio.h>

int main(void){
  int n;
  scanf("%d", &n);
  int s[n];
  for(int i=0; i<n; i++) scanf("%d", &s[i]);
  
  int q;
  scanf("%d", &q);
  int t[q];
  for(int i=0; i<q; i++) scanf("%d", &t[i]);
  
  int cou=0;
  for(int i=0; i<q; i++){
    for(int j=0; j<n; j++){
      if(t[i]==s[j]){
        cou++;
        break;
      }
    }
  }
  
  printf("%d\n", cou);
  return 0;
}


