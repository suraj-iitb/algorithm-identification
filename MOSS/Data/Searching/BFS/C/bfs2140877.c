#include<stdio.h>
#define MAX 100000
#define INFTY 1000000000
int M[100][100],d[100], Q[MAX];
int tt, n, tail=0, head=0;

int isEmpty() {
    return (head==tail);
}

int isFull() {
    return (head==(tail + 1) % MAX);
}

void enqueue(x) {
   Q[tail]=x;
   tail=(tail+1)%MAX;
}

int dequeue() {
   int x;
   head=(head+1)%MAX;
  return x;
}

void dfs(int s) {
  int i, v;
  enqueue(s);
  for(i=0; i<n; i++)
    d[i]=INFTY;
  d[s]=0;
  int u;
  while (! isEmpty()) {
    u=Q[head]; dequeue();
    for (v=0; v<n; v++) {
      if (M[u][v]==0) continue;
      if (d[v]!=INFTY) continue;
      d[v]=d[u]+1;
      enqueue(v);
    }
  }
  for (i=0; i<n; i++) {
    printf("%d %d\n", i+1, ((d[i]==INFTY)?(-1):d[i]));
  }
}

int main() {

  int  u, k, i, j, v;

  scanf("%d", &n);

  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      M[i][j]=0;

  for (i=0; i<n; i++) {
    scanf("%d %d", &u, &k);
    u=u-1;
    for (j=0; j<k; j++) {
      scanf("%d", &v);
      v=v-1;
      M[u][v]=1;
    }
  }

  dfs(0);

  return 0;

}
