#include <stdio.h>
#define MAX 10000
int main(void){
	int n,i;
	scanf("%d",&n);
	int A[n+1];//入力の配列
	int B[n],C[MAX+1];//カウントの配列
	for(i=0;i<MAX;i++){
		C[i]=0;// カウントの初期化
	}
	for(i=0;i<n;i++){
		scanf("%d",&A[i+1]);
		C[A[i+1]]++;//要素をカウントさせる
	}
	for(i=1;i<=MAX;i++){//0～要素の最大値にカウントされている
		//累積和を求める
		C[i]=C[i]+C[i-1];
	}
	for(i=1;i<=n;i++){
		B[C[A[i]]]=A[i];//表示配列に代入
		C[A[i]]--;//カウントを減らす
	}
	
	for(i=1;i<=n;i++){
		if(i>1){
			printf(" ");
		}
		printf("%d",B[i]);//Bを出力
	}
	printf("\n");
	
	return 0;
}

