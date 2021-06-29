#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int N,count=0;
	vector<int> A;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		A.push_back(a);
	}
	int min;
	for (int i = 0; i < N - 1; i++) {
		min = i;
		bool flag = false;
		for (int j = i+1; j < N; j++) {
			if (A[j] < A[min]) {
				min = j;
				flag = true;
			}
		}
		swap(A[i], A[min]);
		count += flag;
	}
	for (int i = 0; i < N-1; i++) {
		printf("%d ", A[i]);
	}
	printf("%d\n%d\n", A[N - 1], count);
	return 0;
}
