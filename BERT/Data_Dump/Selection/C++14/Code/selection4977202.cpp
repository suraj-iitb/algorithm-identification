#include <cstdio>
using namespace std;
int SelectionSort(int* arr, int L, int R) {
	int cnt=0;
	for(int i=L; i<=R; i++) {
		int mini = i;
		for(int j=i+1; j<=R; j++) if(arr[j]<arr[mini]) { mini=j; }
		if(mini!=i) { int t=arr[i]; arr[i]=arr[mini]; arr[mini]=t; ++cnt; }
	}
	return cnt;
}
int main() {
	int N;
	scanf("%d", &N);
	int* arr = new int[200];
	for(int i=1; i<=N; i++) scanf("%d", &arr[i]);
	int cnt = SelectionSort(arr, 1, N);
	for(int i=1; i<=N; i++) printf("%d%c", arr[i], i==N ? '\n' : ' ');
	printf("%d\n", cnt);
	return 0;
}
