#include<stdio.h>
#include<stdlib.h>

int *s;
int *t;

int linearsearch(int key,int n)//見つかれば1,でなければ0を返す
{
	int i=0;
	while(s[i]!=key){
		i++;
		if(i==n) return 0;
	}
	return 1;
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
	for(i=0;i<q;i++){
		cnt+=linearsearch(t[i],n);//cntに返り値を加算
	}
	printf("%d\n",cnt);
	free(s);
	free(t);
}
