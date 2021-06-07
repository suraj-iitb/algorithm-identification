#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int discover[MAX];
int finish[MAX];
int time;

void dfp(int id, int n) {
  // 0-origin
  int i;
  if (finish[id] != 0) {
    return;
  }
  else if (discover[id] == 0){
    discover[id] = (++time);
  }

  for (i = 0; i < n; i++) {
    if (adj[id][i] == 1 && discover[i] == 0) {
      discover[i] = (++time);
      dfp(i, n);
    }
  }
  finish[id] = (++time);
}

int main() {
  int i, j;
  int n, index, k, v;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      adj[i][j] = 0;
    }
    discover[i] = 0;
    finish[i] = 0;
  }

  
  for (i = 0; i < n; i++) {
    scanf("%d %d", &index, &k);
    for (j = 0; j < k; j++) {
      scanf("%d", &v);
      adj[index - 1][v - 1] = 1;
    }
  }

  time = 0;
  for (i = 0; i < n; i++) {
    dfp(i, n);
  }

  for (i = 0; i < n; i++) {
    printf("%d %d %d\n", i+1, discover[i], finish[i]);
  }
  
  return 0;
}

