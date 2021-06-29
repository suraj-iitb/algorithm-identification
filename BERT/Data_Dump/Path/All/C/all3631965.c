#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <queue>

#define INF 214748364000

using namespace std;

struct edge { int from,to,cost;};

int main(){
	int V,E,r,
	    s,t,d;
long long int score[100][100];
	vector<edge> G;
	bool nl=true;
	
	scanf("%d %d",&V,&E);
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			score[i][j] = INF;
		}
	}
	for(int i=0;i<E;i++){
		scanf("%d %d %d",&s,&t,&d);
		score[s][t] = d;
	}
	for(int i=0;i<V;i++) score[i][i] = 0;
	
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			for(int k=0;k<V;k++){
				if(score[j][i]!=INF && score[i][k]!=INF){
					score[j][k] = min(score[j][k],score[j][i] + score[i][k]);
				}
			}
		}
	}
	for(int i=0;i<V;i++){
		if(score[i][i]<0){
			nl=false;
			break;
		}
	}
	
	
	if(nl){
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				if(score[i][j]==214748364000) printf("INF");
				else printf("%d",score[i][j]);
				if(j!=V-1) printf(" ");
			}
			printf("\n");
		}
	}
	else printf("NEGATIVE CYCLE\n");
		
	return 0;
}
