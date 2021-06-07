#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Node {
	int d, c, k;
	int v[101];
};

struct Node node[101];

#define LEN 100000

struct Process
{
	char name[11];
	int time;
};

int que[LEN];
int head = 0, tail = 0;

void enqueue(int a) {
	que[tail] = a;
	if (tail == LEN - 1)
		tail = 0;
	else
		tail++;
}

int dequeue() {
	int n = head;
	if (head == LEN - 1)
		head = 0;
	else
		head++;
	return que[n];
}

void breadth_first() {
	int u, v;
	while (head != tail) {
		u = dequeue();
		for (int i = 0; i < node[u].k; i++) {
			v = node[u].v[i];
			if (node[v].c != 1) {
				node[v].d = node[u].d + 1;
				enqueue(v);
			}
			node[v].c = 1;
		}
	}
}

int main(void) {
	int n, u, k, v;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &u);
		scanf("%d", &k);
		node[u].k = k;
		node[u].c = 0;
		node[u].d = -1;
		for (int j = 0; j < k; j++) {
			scanf("%d", &v);
			node[u].v[j] = v;
		}
	}

	enqueue(1);
	node[1].d = 0;
        node[1].c = 1;
	breadth_first();

	for (int i = 1; i <= n; i++) {
		printf("%d %d\n", i, node[i].d);
	}

	
	return 0;
}
