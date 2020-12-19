#include <iostream>
using namespace std;

int A[100], N, sw;

int bubbleSort() {
    bool flag = 1;
    int sw = 0;
    int i = 0;

    while (flag) {
        flag = 0;
        for (int j = N - 1; j >= i; j--) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j -1]);
                flag = 1;
                sw++;
            }
        }
        i++;
    }
    return sw;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    sw = bubbleSort();
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;
}

