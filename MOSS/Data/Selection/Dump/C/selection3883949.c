#include<stdio.h>

int main(void)
{
    int a[100],n,i,j,box1,count=0,minv,v,p;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);//配列読み込み
	for(i=0;i<n;i++){//i ソート済みの配列番号
		minv=101;//制約条件より最大値を格納
		for(j=i;j<n;j++){//未ソート部分から最小値を捜索
			if(a[j]<minv){
				minv=a[j];
				v=j;
			}
		}
		if(minv!=a[i]){//最小値が左端でなければ交換
			box1=a[i];
			a[i]=minv;
			a[v]=box1;
			count++;
		}
	}
	for(i=0;i<n;i++){
	    	printf("%d",a[i]);
	    	if(i!=n-1) printf(" ");
		}
		printf("\n%d\n",count);
	
	return 0;
}
