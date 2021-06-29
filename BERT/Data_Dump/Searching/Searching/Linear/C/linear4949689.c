#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int search(int A[], int n,int key)
{
	int i=0;
	A[n]=key;
	while(A[i]!=key)//A[i]とkeyが異なるまで繰り返し
	{
		i++;
	}
	return i!=n;
}
int main(void)
{
	int i;
	int n,A[10000+1],q;
	int key,x=0;
	
	scanf("%d", &n);
	
	for(i=0;i<n;i++)//キーボードからA[i]に読み込み
	{
		scanf("%d",&A[i]);
	}
	
	scanf("%d",&q);
	
	for(i=0;i<q;i++)//キーボードからkeyに読み込み
	{
		scanf("%d",&key);
		if(search(A,n,key))//線形探索のクラスを実行
		{
			x++;
		}
	}
	printf("%d\n",x);
	
	return 0;
}
