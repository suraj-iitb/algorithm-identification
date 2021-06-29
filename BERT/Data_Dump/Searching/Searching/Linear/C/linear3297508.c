#include<stdio.h>

#define N 10000
#define Q 10000

int main() {
  int S[N];
  int T[Q];
  int i,j,x,y,count = 0;

  scanf("%d",&x);

  for(i = 0; i < x; i++) {
    scanf("%d",&S[i]);
  }

  scanf("%d",&y);

  for(i = 0; i < y; i++) {
    scanf("%d",&T[i]);
  }

  for(i = 0; i < y; i++) {
    for(j = 0; j < x; j++) {
      if(S[j] == T[i]) {
	count++;
	break;
      }
    }
  }

  printf("%d\n",count);

  return 0;
}

