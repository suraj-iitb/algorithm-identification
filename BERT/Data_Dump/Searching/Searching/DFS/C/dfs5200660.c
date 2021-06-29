#include <stdio.h>

typedef struct{
	int prev;
	int num; //nextの個数
	int next[100];
	int start;
	int end;
}node;

node Graph[100];
int nowtime = 0;
int rec[100];

/* 
 * 再帰、最初にstart,最後にend更新。真ん中で再帰呼び出し
 */

void walk(int start){
	int i, key;
	rec[start] = 1;
	nowtime++;
	Graph[start].start = nowtime;
	if(Graph[start].num > 0){
		for(i = 0; i < Graph[start].num; i++){
			key = Graph[start].next[i];
			if(rec[key] == 0){
				walk(Graph[start].next[i]);
			}
		}
	}
	nowtime++;
	Graph[start].end = nowtime;
}

int main(){
	int i, j, n, key;
	
	scanf("%d", &n); //頂点の個数を記録
	
	for(i = 1; i <= n; i++){
		Graph[i].prev = -1;
	}
	
	for(i = 0; i < n; i++){
		scanf("%d", &key); //頂点番号
		scanf("%d", &Graph[key].num); //nextの個数
		for(j = 0; j < Graph[key].num; j++){
			scanf("%d", &Graph[key].next[j]);
			Graph[Graph[key].next[j]].prev = key;
		}
		rec[i] = 0;
	}
	
	//printf("\nstart\n");
	
	walk(1);
	for(i = 2; i <= n; i++){
		if(Graph[i].prev == -1){
			walk(i);
		}
	}
	
	for(i = 1; i <= n; i++){
		printf("%d ", i);
		printf("%d %d", Graph[i].start, Graph[i].end);
		printf("\n");
	}
	
	return 0;
}

