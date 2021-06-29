#include <iostream>
using namespace std;

void swap(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
    return;
}

void bubbleSort(int *A, int N, int &count) {
    int flag = 1, j;
    while(flag) {
        flag = 0;
        for(j=N-1; j>0; --j) {
            if(A[j] < A[j-1]) {
                swap(A[j], A[j-1]);
                flag = 1;
                ++count;
            }
        }
    }
    return;
}

int main() {
    int N;
    cin >> N;
    int A[N], i, count=0;
    for(i=0; i<N; ++i) cin >> A[i];

    bubbleSort(A, N, count);
    cout << A[0];
    for(i=1; i<N; ++i) cout << ' ' << A[i];
    cout << endl;
    cout << count << endl;

    return 0;
}
