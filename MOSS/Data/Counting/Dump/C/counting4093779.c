#include<stdio.h>

#define vMAX 10001
#define nMAX 2000001
int n,A[nMAX],B[nMAX];

void CountingSort(void){
	int i,cnt[vMAX];
	for(i=0;i<vMAX;i++){
		cnt[i]=0;
	}

	for(i=0;i<n;i++){
		cnt[ A[i] ]++;
	}

	for(i=1;i<vMAX;i++){
		cnt[i]+=cnt[i-1];
	}

	for(i=0;i<n;i++){
		B[ cnt[A[i]] ]=A[i];	cnt[A[i]]--;
	}
}

int main(){
	int i;
	scanf("%d",&n);

	for(i=0;i<n;i++)scanf("%d",&A[i]);
	CountingSort();
	for(i=1;i<=n;i++){
		if(i>1)printf(" ");
		printf("%d",B[i]);
	}printf("\n");
	return 0;
}

