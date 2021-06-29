#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int S[1000000],n;

int binarySearch(int t)
{
	int left=0;
	int right=n;
	int mid;
	while(left<right)
	{
		mid=(left+right)/2;
		if(t==S[mid])return 1;
		if(t>S[mid])left=mid+1;
		else if(t<S[mid])right=mid;
	}//配列の中央から探索し、中央がtでなければｔの大小によってleft、rightを探索する作業を発見まで続ける
	return 0;
}
int main()
{
	int i,q,T,count;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&S[i]);
	}
	scanf("%d",&q);
	count=0;
	for(i=0;i<q;i++)
	{
		scanf("%d",&T);
		if(binarySearch(T))count++;
	}//Tを入力していくごとに探索し、見つかればcountを増やす
	printf("%d\n",count);
	return 0;
}
