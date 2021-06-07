#include <stdio.h>
#include <stdlib.h>


typedef struct{
	int t_d;	// タイムスタンプ、発見時刻
	int t_v;	// タイムスタンプ、完了時刻
	int parent;	// どの頂点からのものか
	int rinsetu_n;	// 隣接する頂点の数
	int *rinsetu;
}GRAPH_T;

GRAPH_T *GRAPH;

int TIME = 1;


void Dfs(int vertex)
{
	int n;
	int i;


	if(GRAPH[vertex].t_d != -1){
		return;
	}else
		GRAPH[vertex].t_d = TIME++;

	n = GRAPH[vertex].rinsetu_n;

	// 隣接頂点がなければ戻る
	if(n == 0){
		GRAPH[vertex].t_v = TIME++;
		return;
	}

	for(i = 0; i < n; i++)
		Dfs(GRAPH[vertex].rinsetu[i]);

	GRAPH[vertex].t_v = TIME++;
}


int main()
{
	int n;
	int id, kazu;
	int num;
	int flag = 0;
	int i, j;


	scanf("%d", &n);

	GRAPH = (GRAPH_T *)malloc(sizeof(GRAPH_T) * (n + 1));

	for(i = 0; i < n; i++)
		GRAPH[i].parent = -1;

	for(i = 0; i < n; i++){
		scanf("%d %d", &id, &kazu);
		GRAPH[id].t_d = -1;
		GRAPH[id].rinsetu_n = kazu;

		if(kazu != 0){
			GRAPH[id].rinsetu = (int *)malloc(sizeof(int) * kazu);
			for(j = 0; j < kazu; j++){
				scanf("%d", &num);
				GRAPH[id].rinsetu[j] = num;
				GRAPH[num].parent = id;
			}
		}
	}

	// rootを求める
	i = 0;
	while(++i <= n){
		if(GRAPH[i].parent == -1){
			flag = 1;
			Dfs(i);
		}
	}
	if(flag != 1)
		Dfs(1);

	for(i = 1; i <= n; i++)
		printf("%d %d %d\n", i, GRAPH[i].t_d, GRAPH[i].t_v);

	return 0;
}
