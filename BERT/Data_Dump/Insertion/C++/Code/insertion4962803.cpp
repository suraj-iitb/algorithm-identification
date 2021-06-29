#include<cstdio>

int a[105];

void out(int N){
	for (int i = 0; i < N - 1; i++){
		printf("%d ", a[i]);
	}
	printf("%d\n", a[N - 1]);
	return;
}

void insertion(int N){
	for (int i = 1; i < N; i++){
		int temp = a[i];
		for (int j = 0; j < i; j++){
			if (a[j] > temp){
				for (int k = i; k > j; k--){
					a[k] = a[k - 1];
				}
				a[j] = temp;
				break;
			}
		}
		out(N);
		//if (i != N - 1)	printf("\n");
	}
	return;
}

int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &a[i]);
	}
	out(N);
	//printf("\n");
	insertion(N);
	return 0;
}
