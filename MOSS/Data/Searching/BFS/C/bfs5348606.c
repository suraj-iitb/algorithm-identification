#include <stdio.h>
#include <math.h>
#include <string.h> 
#include <stdlib.h>
#include <stdbool.h>
#define ll long long
#define PI acos(-1)
#define ichi 1000000007

#define INF (1 << 21)

int n;
int M[100][100], d[100];

int queue[100], head, tail;

void enqueu (int x) {
  queue[tail] = x;
  tail = (tail + 1) % 100;
  return ;
}

int dequeue () {
  int x = queue[head];
  head = (head + 1) % 100;
  return x;
}

int Qempty () {
  return head == tail;
}

void bfs (int x) {
  head = 0;
  tail = 0;
  
  for (int i = 0; i < n; i++) d[i] = INF;

  d[0] = 0;

  enqueu(x);

  int t;
  while (Qempty() != 1) {
    t = dequeue();
    //printf("%d %d\n", head, tail);
    for (int i = 0; i < n; i++) {
      if (M[t][i] != 1) continue;
      if (d[i] != INF) continue;
      d[i] = d[t] + 1;
      enqueu(i);
    }
  }
}


int main () {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      M[i][j] = 0;
    }
  }
  int u, k, v;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &u, &k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &v);
      M[u-1][v-1] = 1;
    }
  }
  
  bfs(0);
  
  for (int i = 0; i < n; i++) {
    printf("%d %d\n", i + 1, ((d[i] == INF) ? -1 : d[i]));
  }
  return 0;
}
