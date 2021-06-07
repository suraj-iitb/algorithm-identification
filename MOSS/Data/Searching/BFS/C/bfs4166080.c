#include <stdio.h>

#define INF 1000000000

int R[101][101]; // 0:root is not exist 1:root exist
int d[101]; // reserve a distant from start
int color[101]; // 0:white 1:gray 2:black
int nm;

struct queue
{
	int arr[100];
	int first;			//次にDEQする配列の添え字
	int last;			//次にENQする配列の添え字
};

struct queue Q;

int enq(int input)
{
	if (Q.arr[Q.last] == 0) { 
		Q.arr[Q.last] = input;
		Q.last++;
		return 0;
	}
	else
	{
		printf("これ以上データを追加できません。\n");
		return -1;
	}
}

int deq()
{
	int output = Q.arr[Q.first];

	if (output != 0)
	{
		Q.arr[Q.first] = 0;
		Q.first++;
		return output;
	}
	else
	{
		printf("データがありません。\n");
		return -1;
	}
}

void init_queue(struct queue que)
{
	int i;

	for (i = 0; i <= 100; i++) Q.arr[i] = 0;

	Q.first = 0;
	Q.last = 0;
}

void bfs(int s){
    int i, j, u, v;

    for(i = 0; i < 101; i++){
        color[i] = 0;
        d[i] = -1;
    }

    color[s] = 1;
    d[s] = 0;
    
	enq(s);
	
	while(Q.first != Q.last){
		u = deq();
		for(v = 1; v <= nm; v++){
			if(R[u][v] == 1 && color[v] == 0){
				color[v] = 1;
				d[v] = d[u] + 1;
				enq(v);
			}
			color[u] = 2;
		}
	}

}

int main(){
    int i, j, snm, nnm, lnm;

	init_queue(Q);

    for(i = 0; i < 101; i++){
        for(j = 0; j < 101; j++){
            R[i][j] = 0;
        }
    }

    scanf("%d", &nm);

    for(i = 0; i < nm; i++){
        scanf("%d%d", &nnm, &snm);
        for(j = 0; j < snm; j++){
                scanf("%d", &lnm);
                R[nnm][lnm] = 1;
        }
    }

	bfs(1);

	for(i = 1; i <= nm; i++){
		printf("%d %d\n", i, d[i]);
	}

    return 0;
}
