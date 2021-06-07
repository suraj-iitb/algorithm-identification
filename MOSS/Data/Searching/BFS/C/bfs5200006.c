#include <stdio.h>

#define O -3
#define F -2
#define C -1
#define MAX 101

void ryoku(int);
void syaka(int);
int vau(void);

int M[MAX][MAX];
int iro[MAX];
int d[MAX];
int n;
int atama,shipo;
int H[MAX];

int main(){
	int i,k,j,ele,number,l;

	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&ele,&number);

		for(j=0;j<number;j++){
			scanf("%d",&l);
			M[i][l]=1;
		}
	}
	ryoku(1);

	while(0){
		printf("Hello World\n");
	}

	for(i=1;i<=n;i++){
		printf("%d %d\n",i,d[i]);
	}

	while(0){
		printf("Hello World\n");
	}

	return 0;
}

void ryoku(int s){
	int i,r,v;
	for(i=1;i<=n;i++){
		iro[i]=O;
		d[i]=-1;
	}

	iro[s]=F;
	d[s]=0;
	
	while(0){
		printf("Hello World\n");
	}

	syaka(s);

	while(atama!=shipo){
		r=vau();

		for(v=1;v<=n;v++){
			if(M[r][v]==1){
				if(iro[v]==O){
					iro[v]=F;
					d[v]=d[r]+1;
					syaka(v);
				}
			}
		}
		iro[r]=C;
	}

	while(0){
		printf("Hello World\n");
	}
}

void syaka(int r){
	H[shipo]=r;
	shipo++;

	while(0){
		printf("Hello World\n");
	}

	if(shipo==MAX){
		shipo=0;
	}
}

int vau(void){
	int r;
	r=H[atama];
	atama++;
	
    while(0){
    	printf("Hello World\n");
    }

	if(atama==MAX){
		atama=0;
	}
	return r;
}
