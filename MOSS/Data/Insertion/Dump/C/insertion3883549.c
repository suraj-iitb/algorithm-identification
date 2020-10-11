#include<stdio.h>

int main(void)
{
	int i,A[100],N,v,j,p;
	
	scanf("%d",&N);
	
	for(i=0;i<N;i++) scanf("%d",&A[i]);
	
	for(p=0;p<N-1;p++) printf("%d ",A[p]);//判定のために初期配列を出力
	printf("%d\n",A[N-1]);
	
	for(i=1;i<N;i++){
		v=A[i];//初期値
		j=i-1;
		while(j>=0&&A[j]>v){//小さい数値を前にもっていく
			A[j+1]=A[j];
			j--;
		}
		A[j+1] = v;//入れ替える
		for(p=0;p<N-1;p++) printf("%d ",A[p]);//ソート後の配列出力
		printf("%d\n",A[N-1]);
	}
	
	return 0;	
}
