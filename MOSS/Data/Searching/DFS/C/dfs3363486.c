#include <stdio.h>
#define MAX 101
#define WHITE 1
#define GRAY 2
#define BLACK 3

typedef struct{
  int tyo, de, list[MAX], color, stime, etime;
} node;

int n, time, tree[MAX][MAX] = {};

void df(node *);
void go(int, node *);

int main() {
  int i, j;
  node node[MAX];

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    scanf("%d %d", &node[i].tyo, &node[i].de);
    for(j = 0 ; j < node[i].de; j++){
      scanf("%d",&node[i].list[j]);
      tree[node[i].tyo][node[i].list[j]] = 1;
    }
  }

  df(node);

  for(i = 0 ; i < n ; i++) {
    printf("%d %d %d\n",node[i].tyo,node[i].stime,node[i].etime);
  }

  return 0;
}

void df(node *node) {
  int i;

  for(i = 0 ; i < n ; i++) {
    node[i].color = WHITE;
  }

  time = 0;

  for(i = 0 ; i < n ; i++){
    if(node[i].color == WHITE) go(i, node);
  }

}

void go(int x, node *node)
{
  int i, j, in;

  node[x].color = GRAY;
  node[x].stime = ++time;

  for(i = 0; i < node[x].de; i++){
    for(j = 0; j < n ; j++){
      if(node[x].list[i] == node[j].tyo) in = j;
    }
    if(tree[node[x].tyo][node[x].list[i]] == WHITE && node[in].color == WHITE) {
      go(in, node);
    }
  }

  node[x].color = BLACK;
  node[x].etime = ++time;

}

