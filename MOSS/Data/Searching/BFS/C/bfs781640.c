#include <stdio.h>
#include <stdlib.h>

struct node_t {
	int key;
	struct node_t *next;
};
typedef struct node_t Node;

Node *enqueue(Node *node, int key) {
	Node *p, *q;

	if (node == NULL) {
		node = malloc(sizeof(Node));
		node->key = key;
		node->next = NULL;
		return node;
	}

	for (p = node; p != NULL; p = p->next) {
		q = p;
	}
	q->next = malloc(sizeof(Node));
	q->next->key = key;
	q->next->next = NULL;
	return node;
}

Node *dequeue(Node *node, int *key) {
	Node *p;

	if (node != NULL) {
		*key = node->key;
		p = node->next;
		free(node);
		return p;
	}
	return NULL;
}

int main(void) {
	int num, i, j, k, u;
	int wayto[101][101] = {{0}};
	int d[101];
	Node *q = NULL;

	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d %d", &u, &k);
		for (j = 0; j < k; j++) {
			scanf("%d", &wayto[u-1][j]);
		}
	}

	d[0] = 0;
	for (i = 1; i < num; i++) {
		d[i] = -1;
	}
	q = enqueue(q, 0);

	while (q != NULL) {
		q = dequeue(q, &u);
		for (i = 0; i < num; i++) {
			k = wayto[u][i] - 1;
			if (d[k] < 0) {
				d[k] = d[u] + 1;
				q = enqueue(q, k);
			}
		}
	}

	for (i = 0; i < num; i++) {
		printf("%d %d\n", i+1, d[i]);
	}
	return 0;
}
