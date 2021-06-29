#include <stdio.h>

int sort(int *p_num, int nn){
	int i, v, j, k;

	for(i=1; i<=nn-1; i++){
		v = p_num[i];
		j = i - 1;
		while( j >= 0 && p_num[j]> v ){
			p_num[j+1] = p_num[j];
			j--;
		}
		p_num[j+1] = v;
		for( k=0; k<nn; k++ ){
			printf("%d", p_num[k]);
			if(k == nn-1) continue;
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}
int main(){
	int i, n, num[1000];

	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		scanf(" %d", &num[i]);
	}

	
	for(i=0; i<n; i++){
		printf("%d", num[i]);
		if(i == n-1) continue;
		printf(" ");
	}
	printf("\n");

	sort(&num[0], n);

//	printf("hello\n");

	//getchar();
	//getchar();
	return 0;
}
