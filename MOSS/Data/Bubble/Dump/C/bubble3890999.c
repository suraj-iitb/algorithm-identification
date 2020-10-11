#include<stdio.h>

int main(void)
{
	int a[100],n,i,j,box,count=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);//配列読み込み
	for(i=0;i<n-1;){ //i ソート済みの配列番号
		for(j=n-1;j>=i;j--){ //末尾からソート済みまでの範囲をソート
			if(j!=0&&a[j-1]>a[j]){//隣接交換
				box=a[j-1];
				a[j-1]=a[j];
				a[j]=box;
				count++;//交換実行毎にcountをインクリメント
			}
			if(i==j) i++;//ソート済みまでいけばiをインクリメント
			
		}
	}
	
	for(i=0;i<n;i++){
	    printf("%d",a[i]);
	    if(i!=n-1) printf(" ");
	}
	printf("\n%d\n",count);
			
	return 0;
}
