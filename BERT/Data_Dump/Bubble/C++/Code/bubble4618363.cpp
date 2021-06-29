#include <iostream>
using namespace std;

int bubbleSort(int A[], int N) {
    int flag = 1;
    int tmp, c = 0;
    while (flag == 1) {
        flag = 0;
        for (int j = N-1; j >= 1; j--) {
            if (A[j] < A[j-1]) {
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = 1;
                c++;
            }
        }
    }
    for(int i = 0; i < N-1; i++) cout << A[i] << " ";
    cout << A[N-1] << endl;
    return c;
}

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) cin >> A[i];

    int c = bubbleSort(A, N);
    cout << c << endl;
}
