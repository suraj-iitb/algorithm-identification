#include<stdio.h>

void show(int *hai,int N);

int main(void){
	int hai[100],i,N,j,flag=1;
	int temp,count=0;

	scanf("%d",&N);
	//printf("%d \n",N);

	for(i=0;i<N;i++){
		scanf("%d",&hai[i]);
		//printf("%d",hai[i]);
	}

	while(flag){
		flag=0;
		for(j=N-1;j>=1;j--){
			if(hai[j]<hai[j-1]){
				temp=hai[j-1];//tempにhaiのj-1を代入
				hai[j-1]=hai[j];//hai[j-1]をhai[j]の値にする
				hai[j]=temp;
				flag=1;
				count++;
			}
		}
	}

	show(hai,N);

	printf("%d\n",count);
}

void show(int *hai,int N){
	int i;
	for(i=0;i<N;i++){
		printf("%d",hai[i]);
		if(i!=N-1)printf(" ");
	}
	printf("\n");
}
