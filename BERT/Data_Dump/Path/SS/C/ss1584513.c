#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <cstdlib>
#include <queue>
#include <vector>
#include <set>
#include <stdio.h>
#include <cstdio>
using namespace std;
int V,E,R,S[500010],T[500010],D[500010];
int C[100010];
const int Inf = 10000*100000+100;

int main() {
	cin >> V >> E >> R;
	for (int i = 0; i < E;i++) {
		cin >>S[i] >> T[i] >> D[i];
	}
	for (int i = 0; i < V;i++) {
		C[i]= Inf;
	}
	C[R]=0;
	for (int i = 0; i < V;i++) {
		bool update = false;
		for (int j=0;j <E;j++) {
			int s= S[j], t=T[j],d=D[j];
			if (C[s] < Inf && C[t] > C[s] + d) {
				C[t] = C[s] + d;
				update = true;
			}
		}
		if(!update) break;
	}
	for (int i =0;i < V;i++){
		if (C[i] == Inf) cout << "INF" << endl;
		else cout << C[i] <<endl;
	}
}
