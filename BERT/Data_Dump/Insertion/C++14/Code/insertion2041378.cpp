#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    size_t N;
    scanf("%zu", &N);

    vector<int> A(N);
    for (size_t i=0; i<N; ++i)
        scanf("%d", &A[i]);

    for (size_t i=1; i<=N; ++i) {
        sort(A.begin(), A.begin()+i);

        for (size_t i=0; i<N; ++i)
            printf("%d%c", A[i], i<N-1? ' ':'\n');
    }

    return 0;
}
