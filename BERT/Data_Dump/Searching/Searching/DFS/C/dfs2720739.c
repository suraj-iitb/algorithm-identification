#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int value;
	int forward;
	int backward;
	int chldNum;
	int *chldHead;
} node;

node *allocNode(int u, int k) {
	node *p = (node *)malloc(sizeof(node));
	p->value = u;
	p->forward = 0;
	p->backward = 0;
	p->chldNum = k;
	p->chldHead = k > 0 ? (int *)malloc(sizeof(int) * k) : NULL;
	return p;
}

void terminate(node **top, int n) {
	int i;
	for (i = 0; i < n; i++)	free(top[i]->chldHead);
	free(top);
}

void dfs(node **top, int u, int *time) {
	int i;
	node *p = top[u];
	if (p->forward > 0) return;
	p->forward = ++(*time);
	for (i = 0; i < p->chldNum; i++) {
		dfs(top, p->chldHead[i], time);
	}
	p->backward = ++(*time);
}

int main() {
	int i, j, u, k, n, v, time;
	node **top;

	scanf("%d", &n);
	top = (node **)malloc(sizeof(node *) * n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &u, &k);
		top[i] = allocNode(u, k);
		for (j = 0; j < k; j++) {
			scanf("%d", &v);
			top[i]->chldHead[j] = v - 1;
		}
	}

	time = 0;
	for (i = 0; i < n; i++)	if (top[i]->forward == 0) dfs(top, i, &time);

	for (i = 0; i < n; i++)
		printf("%d %d %d\n", top[i]->value, top[i]->forward, top[i]->backward);

	terminate(top, n);

	return 0;
}
