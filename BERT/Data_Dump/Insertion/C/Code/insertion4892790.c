#include<stdio.h>
int main(void)
{
    int i,j,k,v,N;//文字の定義
	
    scanf("%d",&N);//配列の中身の数を入力
	int A[N];//配列の定義
	
     for(i=0;i<N;i++)//N回繰り返す
     {
         scanf("%d",&A[i]);//配列そのものを入力
     }
	
	//以下から挿入ソートのアルゴリズム
     for(i=0;i<N;i++)//N回繰り返す
     {
     	v=A[i];
     	j=i-1;
     	
     	while(j>=0&&A[j]>v)//j>=0かつA[j]>v
     	{
     		A[j+1] = A[j];
     		j--;
     		A[j+1] = v;
     	}
     	
     	for(k=0;k<N;k++)
     	{
     		printf("%d",A[k]);//結果の表示
     		if(k!=N-1)printf(" ");//スペースの入力
     	}
     	printf("\n");//改行
     }
     return 0;
}
