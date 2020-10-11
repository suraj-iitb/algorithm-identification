#include<stdio.h>
#include<string.h>

#define MAX 2000001
#define SCORE 10001


int n,nums; 
int counter[SCORE+1], maxi;
int list[MAX+1], sortedList[MAX+1];


void CountingSort() {
  memset(counter,0,sizeof counter);
  int i;
  for(i=0;i<n;++i) ++counter[list[i]];
  for(i=1;i<=maxi;++i) counter[i] += counter[i-1];
  for(i=n-1;i>=0;--i) {
    sortedList[--counter[list[i]]] = list[i];
  }
}

int main() {
  int i, id;
  while( scanf("%d",&n) != EOF ) {
    maxi = 0;
    for(i=0;i<n;++i) {
      scanf("%d",&nums);
      list[i] = nums;
      if( maxi < nums ) maxi = nums;
    }
    CountingSort();
    for(i=0;i<n;++i) {
      if( i ) printf(" ");
      printf("%d",sortedList[i]);
    } puts("");
  }
  return 0;
}

