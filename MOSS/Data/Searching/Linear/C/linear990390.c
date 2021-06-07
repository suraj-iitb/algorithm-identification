#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n, q, i, j, t;
	int *S;
	int cnt = 0;

	scanf("%d", &n);
	S = (int*)malloc(sizeof(int)*n);
	for(i = 0; i < n; i++){
		scanf("%d", S+i);
	}
	
	scanf("%d", &q);

	for(i = 0; i < q; i++){
		scanf("%d", &t);
		for(j = 0; j < n; j++){
			if(S[j] == t){
				cnt++;
				break;
			}
		}
	}

	printf("%d\n", cnt);

	free(S);

	return 0;
}
