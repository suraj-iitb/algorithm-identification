#include <cstdio>
using namespace std;

int BubbleSort(int* arr, int L, int R) {
	int cnt=0;
	for(int i=L; i<=R-1; i++) {
		for(int j=R; j>=i+1; j--) {
			if(arr[j]<arr[j-1]) { int t=arr[j]; arr[j]=arr[j-1]; arr[j-1]=t; ++cnt; }
		}
	}
	return cnt;
}
int arr[200];
int main() {
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d", &arr[i]);
	int cnt = BubbleSort(arr, 1, N);
	for(int i=1; i<=N; i++) printf("%d%c", arr[i], i==N ? '\n' : ' ');
	printf("%d\n", cnt);
	return 0;
}
