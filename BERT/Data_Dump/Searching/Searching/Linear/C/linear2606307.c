#include <stdio.h>

int main(void)
{
	int i, j, n, S[10000], q, T[10000], a, b;
	int count = 0;
	
	scanf("%d",&n);
	
	for(i = 0; i < n; i++){
		scanf(" %d",&S[i]);
	}
	scanf("%d",&q);
	
	for(j = 0; j < q; j++){
		scanf(" %d",&T[j]);
	}
	
	for(a = 0; a < q; a++){
		b = 0;
			while (T[a] != S[b]){
				b++;
				if(b == n)  break;
			}
		if(b != n)  count++;
	}
	
	printf("%d\n",count);
	
	return 0;
}
