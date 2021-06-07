#include <stdio.h>
#include <stdlib.h>

#define NIL -1

typedef struct _node {
	int value;
	int depth;
	int chldNum;
	int *chldHead;
} node;

typedef struct _queue {
	int top;
	int tail;
	int *ary;
} queue;

void enqueu(queue *qp, int u) {
	qp->ary[(qp->tail)++] = u;
}

int dequeu(queue *qp) {
	return qp->ary[(qp->top)++];
}

node *allocNode(int u, int k) {
	node *p = (node *)malloc(sizeof(node));
	p->value = u;
	p->depth = NIL;
	p->chldNum = k;
	p->chldHead = k > 0 ? (int *)malloc(sizeof(int) * k) : NULL;
	return p;
}

void terminate(node **top, int n) {
	int i;
	for (i = 0; i < n; i++)
		free(top[i]->chldHead);
	free(top);
}

void bfs(queue *qp, node **top) {
	int i, u, v;
	enqueu(qp, 0);
	top[0]->depth = 0;
	while (qp->top != qp->tail) {
		u = dequeu(qp);
		for (i = 0; i < top[u]->chldNum; i++) {
			v = top[u]->chldHead[i];
			if (top[v]->depth != NIL) continue;
			top[v]->depth = top[u]->depth + 1;
			enqueu(qp, v);			
		}
	}
}

int main() {
	int i, j, u, k, n, v;
	queue q;
	node **top;

	scanf("%d", &n);
	q.ary = n > 0 ? (int *)malloc(sizeof(int) * n) : NULL;
	q.top = q.tail = 0;

	top = (node **)malloc(sizeof(node *) * n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &u, &k);
		top[i] = allocNode(u, k);
		for (j = 0; j < k; j++) {
			scanf("%d", &v);
			top[i]->chldHead[j] = v - 1;
		}
	}

	bfs(&q, top);

	for (i = 0; i < n; i++)
		printf("%d %d\n", top[i]->value, top[i]->depth);

	terminate(top, n);
	free(q.ary);

	return 0;
}
