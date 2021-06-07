#include <stdio.h>

int n, M[101][101], isVisited[101], stampIN[101], stampOUT[101];
int T = 1;

void visit(int ux){
	stampIN[ux] = T++;
	isVisited[ux] = 1;
	for (int vx = 0; vx < n; vx++){
		if( M[ux][vx] == 1 && isVisited[vx] == 0 ) 
			visit(vx);
	}
	stampOUT[ux] = T++;  
};

int main(){
	int k,u,v;
	scanf("%d\n",&n);
	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			M[ix][jx] = 0;
	for (int jx = 0; jx < n; jx++)
			isVisited[jx] = 0;		
		
	for (int ix = 0; ix < n; ix++){
		scanf("%d%d",&u,&k);
		for (int jx = 0 ; jx < k;jx++){
			scanf("%d",&v);
			M[u-1][v-1]=1;      
		}
	}
	for (int ix = 0; ix < n; ix++)
		if( isVisited[ix] == 0 ) visit(ix);
	for (int ix = 0; ix < n; ix++)
		printf("%d %d %d\n",ix+1,stampIN[ix],stampOUT[ix]);
	return 0;
}
