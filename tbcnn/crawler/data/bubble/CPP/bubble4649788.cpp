#include <iostream>
using namespace std;
static const int MAX_N = 100;

void show(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;
}


int bubbleSort(int A[], int N) {
    int flag = 1;
    int num = 0;
    while (flag) {
        flag = 0;
        for (int i = N - 1; i > 0; i--) {
            if (A[i] < A[i - 1]) {
                int tmp = A[i];
                A[i] = A[i -  1];
                A[i - 1] = tmp;
                flag = 1;
                num++;
            }
        }
    }
    return num;
}

int main() {
    int a[MAX_N] = {0};
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; i++)  cin >> a[i];
    //insertionSort(a, N);
    int num = bubbleSort(a, N);
    show(a, N);
    cout << num << endl;
    return 0;
}
