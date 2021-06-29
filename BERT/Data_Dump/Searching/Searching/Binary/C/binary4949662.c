#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int A[1000000],n;

int binarySearch(int key)
{
	int left=0;//先頭の要素
	int right=n;//末尾の要素
	int mid;//中央の要素
	
	while(left<right)//rightのほうが大きくなるまで繰り返し
	{
		mid=(left+right)/2;//midの値を計算
		if(key==A[mid])return 1;////keyを見つけた時
		if(key>A[mid])left=mid+1;//keyが後半にあるとき
		else if(key<A[mid])right=mid;//keyが前半にあるとき
	}
	return 0;
}
int main()
{
	int i,q,k,x=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		scanf("%d",&k);
		if(binarySearch(k))x++;//合計を増やしていく
	}
	printf("%d\n",x);
	
	return 0;
}
