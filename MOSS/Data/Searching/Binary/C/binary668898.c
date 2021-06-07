#include <stdio.h>
#include <math.h>
#define S_MAX 100000
#define T_MAX 50000
#define FALSE 0

int S[S_MAX] = {0};
int T[T_MAX] = {0};
int n,cnt = 0;
double d_cnt = 0;

void Search(double d, int i){
	if(pow( 2.0, d_cnt) <= n){
		d_cnt++;
		int divide = d * (double)n;
		if(S[divide] < T[i]){
			d = d + pow( 1.0 / 2.0, d_cnt + 1);
			Search(d, i);
		}else if(S[divide] > T[i]){
			d = d - pow( 1.0 / 2.0, d_cnt + 1);
			Search(d, i);
		}else{
			cnt++;
		}
	}
}

int main(void){
	int q,i,j;

	scanf("%d", &n);

	for(i = 0;i < n;i++){
		scanf("%d" ,&S[i]);
	}

	scanf("%d", &q);

	for(i = 0;i < q;i++){
		scanf("%d" ,&T[i]);
	}

	for(i = 0;i < q;i++){
		d_cnt = 0;
		Search(1.0 / 2.0, i);
	}

	printf("%d\n", cnt);

	return 0;
}
