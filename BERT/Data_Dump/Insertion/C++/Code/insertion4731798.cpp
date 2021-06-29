#include<iostream>
using namespace std;

int insertion_sort(int A[], int N) {
    int v, j;
    for (int i = 0; i < N; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A [j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;

        cout << A[0];
        for (int i = 1; i < N; i++) {
            cout << ' ' << A[i];
        }
        cout << endl;
    }
    return 0;
}

int main() {
    int N;
    int A[100];

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    insertion_sort(A, N);

    return 0;

}
