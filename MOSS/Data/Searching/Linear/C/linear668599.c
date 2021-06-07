#include <stdio.h>
#define S_MAX 10000
#define T_MAX 500

int main(void){
	int n,q,i,j,cnt = 0;
	int S[S_MAX] = {0};
	int T[T_MAX] = {0};

	scanf("%d", &n);

	for(i = 0;i < n;i++){
		scanf("%d" ,&S[i]);
	}

	scanf("%d", &q);

	for(i = 0;i < q;i++){
		scanf("%d" ,&T[i]);
	}

	for(i = 0;i < q;i++){
		for(j = 0;j < n;j++){
			if(T[i] == S[j]){
				cnt++;
				break;
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}
