#include<stdio.h>

int BubbleSort(int* a, int n){
	int i,j,cnt=0,tmp;
	for(i=0;i+1<n;i++){
		for(j=n-1;j>=i+1;j--){
			if(a[j-1]>a[j]){
				cnt++;

				tmp=a[j];
				a[j]=a[j-1];
				a[j-1]=tmp;
			}
		}
	}

	return cnt;
}

int main(){
	int i,n,cnt, a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	cnt=BubbleSort(a,n);

	for(i=0;i<n;i++){
		if(i)printf(" ");
		printf("%d",a[i]);
	}printf("\n%d\n",cnt);
	
	return 0;
}

