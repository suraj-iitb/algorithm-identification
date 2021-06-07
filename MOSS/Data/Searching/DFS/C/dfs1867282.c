#include <stdio.h>
#include <stdlib.h>
int n,i,j,u,k,tmp;
int list[100][100]={};
int time=0;
int timelist[100][2];

void search(int y){
	int ii,jj;
	time++;
	timelist[y][0]=time;
	for(jj=0;jj<n;jj++){
		list[jj][y]=0;
	}

	for(ii=0;ii<n;ii++){
		if(list[y][ii]==1){
			search(ii);
		}
	}
	time++;
	timelist[y][1]=time;
}

int main(void) {


	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&u);
		scanf("%d",&k);
		for(j=0;j<k;j++){
			scanf("%d",&tmp);
			list[u-1][tmp-1]=1;
		}
	}
	for(i=0;i<n;i++){
		if(timelist[i][0]==0){
			search(i);}}

	for(j=0;j<n;j++){
		printf("%d %d %d\n",j+1,timelist[j][0],timelist[j][1]);
	}

	return 0;
}
