#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 0;
	scanf("%d", &n);
	int* a = (int *)malloc(sizeof(int) * n);
	int ch,k=0;

	while(scanf("%d", &ch) != EOF){
		a[k] = ch;
		k++;
	}

	for(int i = 0; i < n; i++){
		int v = a[i];
		int j = i-1;
		while(j >= 0 && a[j] > v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;

		for(int j = 0; j < n; j++){
			printf("%d", a[j]);
			if(j != n-1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
