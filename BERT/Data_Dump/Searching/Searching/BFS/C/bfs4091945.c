#include <stdio.h>
#include <stdlib.h>


typedef struct{
	int distance;
	int next_n;
	int *next;
} GRAPH_T;


int main()
{
	int vertex_n;
	GRAPH_T *graph;
	int ring_queue[100];
	int front, rear;
	int id, next_id , n;
	int i, j;


	scanf("%d", &vertex_n);

	graph = (GRAPH_T *)malloc(sizeof(GRAPH_T) *(vertex_n + 1));

	for(i = 0; i < vertex_n; i++){
		scanf("%d %d", &id, &n);
		graph[i + 1].distance = -1;
		graph[i + 1].next_n = n;

		if(n != 0){
			graph[i + 1].next = (int *)malloc(sizeof(int) * n);
			for(j = 0; j < n; j++){
				scanf("%d", &id);
				graph[i + 1].next[j] = id;
			}
		}
	}

	// test
/*	printf("\n");
	for(i = 0; i < vertex_n; i++){
		printf("%d %d", graph[i + 1].distance, graph[i + 1].next_n);
		for(j = 0; j < graph[i + 1].next_n; j++)
			printf(" %d", graph[i + 1].next[j]);
		printf("\n");
	}
*/

	// BFS
	front = rear = 0;
	graph[1].distance = 0;
	ring_queue[rear++] = 1;
	while(front != rear){
		id = ring_queue[(front++) % 100];
		n = graph[id].next_n;

		for(i = 0; i < n; i++){
			next_id = graph[id].next[i];
			if(graph[next_id].distance == -1 || graph[next_id].distance > graph[id].distance + 1){
				graph[next_id].distance = graph[id].distance + 1;
				ring_queue[(rear++) % 100] = graph[id].next[i];
			}
		}
	}

	for(i = 0; i < vertex_n; i++)
		printf("%d %d\n", i + 1, graph[i + 1].distance);

	return 0;
}
