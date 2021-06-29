#include <stdio.h>
#include <stdlib.h>

enum boolean { true, false };
struct node {
  enum boolean is_connected_to[101];
  int distance;
};
struct node graph[101];
int queue[101], head = 1, tail = 1;

void enqueue(int node) {
  queue[tail++] = node;
}

int dequeue() {
  return head != tail ? queue[head++] : -1;
}

void breadthSearch(int current_node) {
  if(current_node == -1) return;

  int i, d = graph[current_node].distance + 1;

  for(i = 1;i < 101;i++) {
    if(graph[current_node].is_connected_to[i] == true && graph[i].distance == -1) {
      enqueue(i);
      graph[i].distance = d;
    }
  }

  breadthSearch(dequeue());
}

int main() {
  int n, i, j, k, node, direction;

  for(i = 1;i < 101;i++) {
    graph[i].distance = -1;

    for(j = 1;j < 101;j++)
      graph[i].is_connected_to[j] = false;
  }

  scanf("%d", &n);
  for(i = 0;i < n;i++) {
    scanf("%d %d", &node, &k);
    for(j = 0;j < k;j++) {
      scanf("%d", &direction);
      graph[node].is_connected_to[direction] = true;
    }
  }

  graph[1].distance = 0;
  breadthSearch(1);

  for(i = 1;i < n + 1;i++) {
    printf("%d %d\n", i, graph[i].distance);
  }
}

