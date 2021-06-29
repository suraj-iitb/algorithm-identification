#include <stdio.h>

int n;
int Adj[101][101] = { 0 };
int d[101];

typedef struct{
	int max;
	int num;
	int front;
	int rear;
	int *que;
}Queue;

void Init(Queue *q, int max);
void Enque(Queue *q, int x);
void Deque(Queue *q, int *x);


int main(void){
	int u, k, v;
	int i, j;

	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d %d", &u, &k);
		for (j = 1; j <= k; j++){
			scanf("%d", &v);
			Adj[u][v] = 1;
		}
	}

	Queue que;
	Init(&que, n*n);
	for (i = 1; i <= n; i++){
		d[i] = -1;
	}

	d[1] = 0;
	Enque(&que, 1);
	while (que.num != 0){
		Deque(&que, &u);
		for (v = 1; v <= n; v++){
			if (Adj[u][v] == 1){
				if (d[v] == -1 || d[v] > d[u] + 1){
					d[v] = d[u] + 1;
					Enque(&que, v);
				}
			}
		}
	}

	for (i = 1; i <= n; i++){
		printf("%d %d\n", i, d[i]);
	}

	return 0;
}

void Init(Queue *q, int max){
	q->max = max;
	q->num = q->front = q->rear = 0;
	q->que = calloc(max, sizeof(int));
}

void Enque(Queue *q, int x){
	q->num++;
	q->que[q->rear++] = x;
	if (q->rear == q->max)
		q->rear = 0;
}

void Deque(Queue *q, int *x){
	q->num--;
	*x = q->que[q->front++];
	if (q->front == q->max)
		q->front = 0;
}
