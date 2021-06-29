#include <cstdio>
#define MAX 1145140
#define INF 1145141919
using namespace std;
int n;
int A[MAX];
int L[MAX / 2], R[MAX / 2];
int cnt;
void merge(int left,int right,int mid) {
	int n1 = mid - left;
	int n2 = right - mid;
	int i;
	for (i = 0; i < n1; i++) {
		L[i] = A[left + i];
	}
	L[n1] = INF;
	for (i = 0; i < n2; i++) {
		R[i] = A[mid + i];
	}
	R[n2] = INF;
	int j = 0, k = 0;
	for (i = left; i < right; i++) {
		cnt++;
		if (L[j] < R[k]) {
			A[i] = L[j];
			j++;
		}
		else {
			A[i] = R[k];
			k++;
		}
	}

}
void mergeSort(int left,int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(mid,right);
		mergeSort(left,mid);
		merge(left,right,mid);
	}
}
int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d",&A[i]);
	}
	mergeSort(0,n);
	for (i = 0; i < n; i++) {
		if (i)printf(" ");
		printf("%d", A[i]);
	}
	printf("\n%d\n", cnt);
}
