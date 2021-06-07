#include<stdio.h>
#include<stdlib.h>

int *s;
int *t;

int binarysearch(int key,int n)//見つかれば1,でなければ0を返す
{
	int i=0;
	int left=0,right=n,mid;
	while(left<right){
		mid=(left+right)/2;//中間を求める
		if(s[mid]==key) return 1;
		else if(key<s[mid]) right=mid;//左側なら探索範囲を左側に変更
		else left=mid+1; //右側なら探索範囲を右側に変更
	}
	return 0;
}

int main(void)
{
	int i;
	int n,q;
	int cnt=0;
	scanf("%d",&n);
	s=(int*)malloc(sizeof(int)*n);//s読み込み
	for(i=0;i<n;i++) scanf("%d",&s[i]);
	scanf("%d",&q);
	t=(int*)malloc(sizeof(int)*q);
	for(i=0;i<q;i++) scanf("%d",&t[i]);//t読み込み
	for(i=0;i<q;i++) cnt+=binarysearch(t[i],n);//cntに返り値を加算
	printf("%d\n",cnt);
	free(s);
	free(t);
}
