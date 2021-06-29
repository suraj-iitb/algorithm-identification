#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N;
    int k;
    vector<int> A;
    scanf("%d", &N);
    for (int i=0; i < N; i++) {
        scanf("%d", &k);
        A.push_back(k);
    }
    for (int i=1; i < N; i++) {
        for (int i=0; i < N; i++) {
            if (i == N-1) {
                printf("%d\n", A.at(i));
            } else {
                printf("%d ", A.at(i));
            }
        }
        int v = A.at(i);
        int j = i-1;
        while (j >= 0 && v < A.at(j)) {
            A.at(j+1) = A.at(j);
            j--;
        }
        A.at(j+1) = v;
    }
    for (int i=0; i < N; i++) {
        if (i == N-1) {
            printf("%d\n", A.at(i));
        } else {
            printf("%d ", A.at(i));
        }
    }
	return 0;
}
