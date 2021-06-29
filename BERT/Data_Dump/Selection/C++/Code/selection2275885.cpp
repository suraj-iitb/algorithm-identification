#include <cstdio>

void trace(int *a, int N){
	int i;
	for(i=0; i<N-1; i++){
		std::printf("%d ", a[i]);
	}
	std::printf("%d\n", a[N-1]);
}

void bubbleSort(int *a, int N){
	int i,j,minj,x,count;
	count = 0;
	for (i=0;i<N; i++){
		minj = i;
		for (j=i; j<N; j++){
			if (a[minj] > a[j]){
				minj = j;
			}
		}
		if (i!=minj){
			x = a[i];
			a[i] = a[minj];
			a[minj] = x;
			count ++;
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
