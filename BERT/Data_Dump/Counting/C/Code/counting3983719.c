#include<stdio.h>
#include<string.h>

#define MAX 2000001
#define MAX_SCORE 10001

typedef struct {
  int id;
  int score;
  int rank;
} Info;

int n; // number of students
int counter[MAX_SCORE+1], maxi;
Info list[MAX+1], sortedList[MAX+1];


void CountingSort() {
  memset(counter,0,sizeof counter);
  int i;
  for(i=0;i<n;++i) ++counter[list[i].score];
  for(i=1;i<=maxi;++i) counter[i] += counter[i-1];
  for(i=n-1;i>=0;--i) {
    sortedList[--counter[list[i].score]] = list[i];
  }
}

int main() {
  int i, id, score;
  while( scanf("%d",&n) != EOF ) {
    maxi = 0;
    for(i=0;i<n;++i) {
      scanf("%d",&score);
      list[i].score = score;
      if( maxi < score ) maxi = score;
    }
    CountingSort();
    for(i=0;i<n;++i) {
      if( i ) printf(" ");
      printf("%d",sortedList[i].score);
    } puts("");
  }
  return 0;
}


