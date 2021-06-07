#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int main(void){
	int n;
	int q;
	scanf("%d",&n);
	int a[n];
	int i;
	for(i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	
	scanf("%d",&q);
	int b[q];
	int j;
	for(j = 0; j < q; j++){
		scanf("%d",&b[j]);
	}
	
	qsort(b, q, sizeof(int), compare_int);
	
	int k = 0;
	int l = 0;
	int r = 0;
	while(k < n){
		if(a[k] == b[l]){
			k = k + 1;
			l = l + 1;
			r = r + 1;
		}
		else if(a[k] > b[l]){
			if(l < q){
				l = l + 1;
			}
			else if(l == q){
				break;
			}
		}
		else{
			k = k + 1;
		}
	}

	printf("%d\n",r);

	return 0;
	}
