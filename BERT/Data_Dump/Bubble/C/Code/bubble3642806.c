#include<stdio.h>

int main(void){

  int frag = 1;
  int MAX = 100;
  int R[MAX], n, j, i, count=0;
  int buffa;
  scanf("%d", &n);

  for(i=0;i<n;i++) scanf("%d", &R[i]);

  while(frag==1){
    frag = 0;
    for(j=n-1;j>=1;j--){
      if(R[j] < R[j-1]){
        buffa = R[j];
        R[j] = R[j-1];
        R[j-1] = buffa;
        count =	count + 1;
        frag = 1;
      }
    }
  }
  for(i=0;i<n-1;i++) printf("%d ", R[i]);
  printf("%d\n", R[n-1]);
  printf("%d\n", count);
  return 0;
}

