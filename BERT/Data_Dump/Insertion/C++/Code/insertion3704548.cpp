#include <bits/stdc++.h>
using namespace std;

//vector毎回出力
void trace(vector<int> v, int N) {
	for (int i = 0; i < N; i++) {
		printf("%d", v.at(i));
		if (i < N - 1) printf(" ");
	}
	printf("\n");
	return;
}

//insertionsort
void insertionsort(vector<int> v, int N) {
	for (int i = 1; i < N; i++) {
		int x = v.at(i);
		int j = i - 1;
		while (j >= 0 && x <  v.at(j)) {
			v.at(j + 1) = v.at(j);
			j--;
		}
		v.at(j + 1) = x;
		trace(v, N);
	}
	return;
}

//main
int main() {
	int N; scanf("%d", &N);
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v.at(i));
	}
	trace(v, N);
	insertionsort(v, N);
	return 0;
}
