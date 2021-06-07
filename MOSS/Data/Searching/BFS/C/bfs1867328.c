#include <stdio.h>
#include <stdlib.h>
int n,i,j,u,k,tmp;
int list[100][100]={};
int lengthlist[100];

void search(int y,int length){
	int ii;
	length++;
	lengthlist[y]=length;


	for(ii=0;ii<n;ii++){
		if(list[y][ii]==1){
			if(lengthlist[ii]<=length&&lengthlist[ii]>=0){
				continue;
			}
			search(ii,length);
		}
	}
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
	lengthlist[i]=-1;
	}
	search(0,-1);



	for(j=0;j<n;j++){
		printf("%d %d\n",j+1,lengthlist[j]);
	}

	return 0;
}
