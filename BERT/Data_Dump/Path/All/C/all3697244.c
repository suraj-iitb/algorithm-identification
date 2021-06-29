#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#define MAX 105

using namespace std;

static const long long INF=(1LL<<32);

int v;
long long a[MAX][MAX];

void floyd() {
	int i,j,k;
	for(k=0;k<v;k++) {
		for(i=0;i<v;i++) {
			if(a[i][k]==INF) continue;
			for(j=0;j<v;j++) {
				if(a[k][j]==INF) continue;
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
}

int main() {
	int e,i,j,k;
	
	scanf("%d %d",&v,&e);
	
	for(i=0;i<v;i++) {
		for(j=0;j<v;j++) {
			if(i==j) a[i][j]=0;
			else a[i][j]=INF;
		}
	}
	
	for(i=0;i<e;i++) {
		int d1,d2,w;
		scanf("%d %d %d",&d1,&d2,&w);
		a[d1][d2]=w;
	}
	
	floyd();
	
	bool negative=false;
	for(i=0;i<v;i++) if(a[i][i]<0)	negative=true;
	
	if(negative) {
		printf("NEGATIVE CYCLE\n");
	} else {
		for(i=0;i<v;i++) {
			for(j=0;j<v;j++) {
				if(j!=0) printf(" ");
				if(a[i][j]==INF) printf("INF");
				else printf("%lld",a[i][j]);
			}
			printf("\n");
		}
	}
	
	return 0;
}
