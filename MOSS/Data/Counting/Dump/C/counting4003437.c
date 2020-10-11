#include<stdio.h>
#include<math.h>

#define MAX 2000000

int CountingSort(int A[], int B[], int n,int k){
	int C[MAX];

	for(int i = 0; i <= k;i++){
		C[i] = 0;
//		for(int o = 0; o < n; o++){printf("%d ",C[o]);}printf("\n");
	}
//	printf("-----------\n");
	// C[i] にiの出現数を記録する 
	for(int j = 0; j < n;j++){
		C[A[j]]++;
//		for(int o = 0; o < n; o++){printf("%d ",C[o]);}printf("\n");
	}
//	printf("-----------\n");
	
	// C[i]にi以下の数の出現数を記録する 
	for(int i = 1; i <= k; i++){
		C[i] = C[i] + C[i-1];
//		for(int o = 0; o < n; o++){printf("%d ",C[o]);}printf("\n");
	}
//	printf("-----------\n");
	
	for(int j = n-1; j >= 0; j--){
		B[C[A[j]]-1] = A[j];
		C[A[j]]--;
//		for(int o = 0; o < n; o++){printf("%d ",C[o]);}printf("\n");
	}
//	printf("-----------\n");

}


int main(){
	int n,k = 0;
	int val[MAX];
	int ans[MAX];
	
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&val[i]);
		k = k < val[i] ? val[i] : k;
		ans[i] = 0;//初期化
	}
	CountingSort(val, ans, n, k);
	
	printf("%d",ans[0]);
	for(int i = 1;i < n; i++){
		printf(" %d",ans[i]);
	}
	printf("\n");
	return 0;
}
