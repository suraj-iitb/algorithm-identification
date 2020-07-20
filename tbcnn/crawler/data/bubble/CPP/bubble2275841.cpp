#include <cstdio>

void trace(int *a, int N){
	int i;
	for(i=0; i<N-1; i++){
		std::printf("%d ", a[i]);
	}
	std::printf("%d\n", a[N-1]);
}

void bubbleSort(int *a, int N){
	int i,j,flag,count,x;
	flag = 1;
	count = 0;
	while (flag){
		flag = 0;
		for (j=N-1; j>0; j--){
			if (a[j] < a[j-1]){
				x = a[j];
				a[j] = a[j-1];
				a[j-1] = x;
				flag = 1;
				count ++;
			}
		}
	}
	trace(a, N);
	std::printf("%d\n", count);
}

int main(){
	int N,i;
	int *a;
	std::scanf("%d", &N);
	a = new int[N];
	for (i=0; i<N; i++){
		std::scanf("%d", &a[i]);
	}
	bubbleSort(a, N);
	return 0;
}
