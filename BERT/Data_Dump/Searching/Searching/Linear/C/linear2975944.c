#include<stdio.h>
#define LEN1 100000
#define LEN2 500

int main(){
  int i, j, count=0;
  int n, q, S[LEN1], T[LEN2];

  scanf("%d", &n);
  for(i=0; i<n; i++)
    scanf("%d", &S[i]);

  scanf("%d", &q);
  for(i=0; i<q; i++)
    scanf("%d", &T[i]);

  for(i=0; i<q; i++){
    for(j=0; j<n; j++){
      if(T[i] == S[j]){
        count++;
        break;
      }
    }
  }

  printf("%d\n", count);

  return 0;
}
