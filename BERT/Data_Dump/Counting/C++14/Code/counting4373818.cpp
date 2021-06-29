#include <iostream>
#define MAX 2000000+1
#define lim 10000+1
#define INF 2*MAX

int A[MAX], result[MAX], counter[lim];

void CountingSort(int A[], int n){

    /* initialize counter */
    for (int i=0; i<lim; i++) counter[i] = 0;

    /* count number of each value */
    for (int i=0; A[i] != INF; i++) counter[A[i]]++;

    /* generate result array */
    int k=0;
    for (int i=0; i<lim; i++) for (int j=0; j<counter[i]; j++) {
        if (counter[i] != 0) result[k++] = i;
    }
    result[k] = INF;
}

int main() {

    /* input */
    int n;
    std::cin >> n;
    for (int i=0; i<n; i++) std::cin >> A[i];
    A[n] = INF;

    /* counting sort */
    CountingSort(A, n);

    /* output */
    for (int i=0; result[i] != INF; i++) std::cout << result[i] << ( result[i+1] != INF  ? " " : "\n");
}
