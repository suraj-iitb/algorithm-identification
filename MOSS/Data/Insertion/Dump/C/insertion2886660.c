#include<stdio.h>
void hai();
int main(void)/**配列の要素数を決める。**/{
	int N;//変数宣言
	scanf("%d",&N);//配列の要素数を決める。

	hai(N);//配列の要素数を引数とし、配列の要素を入れる関数
}

void hai(int N){
	int *hai,i,hairetsu[N],j,k;
	int value;

	hai=hairetsu;

	for(i=0;i<N; i++){

		scanf("%d",&hai[i]);
		printf("%d",hai[i]);
		if(i!=N-1)printf(" ");

	}
	printf("\n");

	for(i=1;i<N;i++){

		value=hai[i];//i列目を変数に記憶させる。
		j=i-1;
		while((j>=0)&&(hai[j]>value)){
			hai[j+1]=hai[j];

			j--;

		}
		hai[j+1]=value;

		for(k=0;k<N;k++){
		    if(k == N-1)printf("%d\n",hai[k]);
		    else printf("%d ",hai[k]);
		}

	}


}

