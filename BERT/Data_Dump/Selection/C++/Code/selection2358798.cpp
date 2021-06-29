#include <iostream>
using namespace std;

void swap(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;

    return;
}

void sectionSort(int *A, int N, int &count) {
    int i, j, minj;

    for(i=0; i<N; ++i) {
        minj = i;
        for(j=i; j<N; ++j) {
            if(A[j] < A[minj])
                minj = j;
        }
        if(minj != i) {
            swap(A[minj], A[i]);
            ++count;
        }
    }

    return;
}

int main() {
    int N;
    cin >> N;
    int A[N], i, count=0;
    for(i=0; i<N; ++i) cin >> A[i];

    sectionSort(A, N, count);
    cout << A[0];
    for(i=1; i<N; ++i) cout << ' ' << A[i];
    cout << endl;
    cout << count << endl;

    return 0;
}
