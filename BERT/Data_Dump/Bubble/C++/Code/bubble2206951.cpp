#include<cstdio>
#include<vector>
using namespace std;

int main()
{
	int N,count=0;
	vector<int> A;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		A.push_back(a);
	}
	bool flag=true;
	while(flag){
		flag = 0;
		for (int j = N - 1; j > 0; j--) {
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
				flag = 1;
				count++;
			}
		}
	}
	for (int i = 0; i < N-1; i++) {
		printf("%d ", A[i]);
	}
	printf("%d\n%d\n", A[N - 1], count);
	return 0;
}
