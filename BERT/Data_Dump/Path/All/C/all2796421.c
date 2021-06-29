#include <bits/stdc++.h>
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define FORq(i, m, n) for(int i = m;i <= n;i++)
#define SCD(n) scanf("%d",&n)
#define SCD2(m,n) scanf("%d%d",&m,&n)
#define SCD3(m,n,k) scanf("%d%d%d",&m,&n,&k)
#define PB push_back
#define MP make_pair
#define PRINTD(n) printf("%d\n",n)
#define PRINTLLD(n) printf("%lld\n",n);
#define DEBUG printf("%s\n","debug")
using namespace std;
typedef pair<int,int> P;
//////////////////////////////////////////////////////
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=jp


const long long INF = 9223372036854775000;
const int VMAX = 102;
const int EMAX = 10000;

struct Edge{
	int from;
	int to;
	int cost;
};


int main() {
	int V,E; SCD2(V,E);
	struct Edge e[EMAX];
	long long d[VMAX][VMAX];
	bool negcycle = false;
	
	REP(i,E){
		int s,t,c;
		SCD3(s,t,c);
		e[i].from = s;
		e[i].to = t;
		e[i].cost = c;
	}
	
	REP(s,V){ //s -> [0..V-1]
		
		REP(i,VMAX){
			d[s][i] = INF;
		}
	
		d[s][s] = 0;
	
		REP(i,V){ // loop V times --> NEGCYCLE

			bool update = false;
			REP(j,E){
				int u = e[j].from;
				int v = e[j].to;
				int c = e[j].cost;
				
				if ((d[s][u] + c < d[s][v]) and (d[s][u] != INF)) {
					d[s][v] = d[s][u] + c;
					update = true;
				}
			}
		
			if ((update) and (i == V-1)){ // NEGCYCLE
				negcycle = true;
			}
			
		}
		
	}
	
	if (negcycle) {
		printf("NEGATIVE CYCLE\n");
		return 0;
	}
	
	REP(s,V){
		REP(i,V-1){
			if (d[s][i] != INF){
				printf("%lld ",d[s][i]);
			}else{
				printf("INF ");
			}
		}
			
		if (d[s][V-1] != INF){
			printf("%lld\n",d[s][V-1]);
		}else{
			printf("INF\n");
		}
		
	}
	
	
	return 0;
}









