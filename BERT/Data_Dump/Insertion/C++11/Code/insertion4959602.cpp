#include <cstdio>
using namespace std;

void prt(int* arr, int L, int R) { for(int i=L; i<=R; i++) printf("%d%c", arr[i], i==R ? '\n' : ' '); }
void InsertionSort(int* arr, int L, int R) {
	for(int i=L+1; i<=R; i++) {
		int j=i-1, key=arr[i];
		for(; j>=1 and arr[j]>key; j--) arr[j+1]=arr[j];
		arr[j+1]=key;
		prt(arr, L, R);
	}
}

int arr[105];
int main() {
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d", &arr[i]);
	prt(arr, 1, N);
	InsertionSort(arr, 1, N);
	return 0;
}
