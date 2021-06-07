#include<stdio.h>
#define N 10000

int main(void){

  int n, q, c=0, i, j;
  int s[N], t[N];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&q);

  for(j=0;j<q;j++){
    scanf("%d",&t[j]);
  }

  for(j=0;j<q;j++){
    for(i=0;i<n;i++){

      if(s[i] == t[j]){
        c++;
        break;
      }
    }
  }

  printf("%d\n", c);

  return 0;
}
