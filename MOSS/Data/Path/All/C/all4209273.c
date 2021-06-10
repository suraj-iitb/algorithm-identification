#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAXV = 110;
const long long INF = (1LL<<32);

ifstream in("apsp.in");

int v, e;
long long int cost[MAXV][MAXV];

int min(int a,int b){
  if(a > b) return b;
  else return a;
}

void Floyd_Warshall(){
	for(int k = 0; k < v; ++k){
		for(int i = 0; i < v; ++i){
			if(cost[i][k]==INF) continue;
			for(int j = 0; j < v; ++j){	
				if(cost[k][j]==INF) continue;
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}	
	}	
}

int main(){	
	int x, y, c;
	cin >> v >> e;
	for(int i = 0; i < v; ++i){
		for(int j = 0; j < v; ++j){
			 	if(i==j) 
			 		cost[i][j]=0;
      	else 
      		cost[i][j]=INF;
		}
  }	
	for(int i = 0; i < e; ++i){
		cin >> x >> y >> c;
		cost[x][y] = c;
	}		

	Floyd_Warshall();

	for(int i = 0; i < v; ++i){
		if(cost[i][i] < 0){
			cout << "NEGATIVE CYCLE" << '\n';
			return 0;
		}
	}
	for(int i = 0; i < v; ++i){
		for(int j = 0; j < v; ++j){
			if(cost[i][j] == INF)
				cout << "INF";
			else 
				cout << cost[i][j];
			if(j == v-1) 
				cout << '\n';
			else 
				cout << " ";
			}
	}
	return 0;
}

