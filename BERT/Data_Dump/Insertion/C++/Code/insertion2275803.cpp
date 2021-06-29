#include <cstdio>

void insertionSort(int *a, int N){
	int i,j,k,v;
	for (i=1; i<N; i++){
		for (k=0; k<N-1; k++){
			std::printf("%d ", a[k]);
		}
		std::printf("%d\n", a[N-1]);
		v = a[i];
		j=i-1;
		while(j>=0 && a[j]>v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
	}
	for (k=0; k<N-1; k++){
		std::printf("%d ", a[k]);
	}
	std::printf("%d\n", a[N-1]);
}

int main(){
	int N, i;
	int *a;
	std::scanf("%d", &N);
	a = new int[N];
	i = 0;
	for (i=0; i<N; i++){
		std::scanf("%d", &a[i]);
	}
	insertionSort(a, N);
	return 0;
}
