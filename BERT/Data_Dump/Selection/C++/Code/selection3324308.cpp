#include <iostream>
using namespace std;

int Selection_sort(int* A, int N) {
    int tmp_minj, minj, j;
    int count = 0;
    for (int i=0; i<N; i++) {
        minj = i;
        tmp_minj = i;
        for (j=i; j<N; j++) {
            if (A[j] < A[minj]) { minj = j; }
        }
        if (tmp_minj != minj) { swap(A[i], A[minj]); count++; }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int* ap;
    ap = a;

    k = Selection_sort(ap, n);

    for (int i=0; i<n; i++){
        if (i == n-1) { cout << a[i] << endl; }
        else { cout << a[i] << " "; }
    }

    cout << k << endl;

    return 0;
}

