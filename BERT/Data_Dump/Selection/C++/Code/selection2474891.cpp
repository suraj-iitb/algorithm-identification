#include <stdio.h>

#define N 100

int main(){
	int n,i;
	int sel[N];

	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&sel[i]);
	}
	int j,minj,tmp,count = 0;
	for(i = 0;i < n -1; i++){
		minj = i;
		for(j = i+1; j< n;j ++){
			if(sel[j] < sel[minj]){
				minj = j;
			}
		}
		if(minj != i){
			tmp = sel[minj];
			sel[minj] = sel[i];
			sel[i] = tmp;
			count++;
		}
	}

	for(i = 0;i < n-1; i++){
		printf("%d ",sel[i]);
	}
	printf("%d\n",sel[i]);
	printf("%d\n",count);
	return 0;
}
