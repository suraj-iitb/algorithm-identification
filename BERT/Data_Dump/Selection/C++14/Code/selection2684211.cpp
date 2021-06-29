#include <iostream>

#define swap(a, b) a^=b^=a^=b

using namespace std;

int main() {

    int N, A[100], count = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N - 1; i++) {
        int min = i;
        for (int j = i + 1; j < N; j++) {
            if (A[min] > A[j]) {
                min = j;
            }
        }
        if (min != i) {
            swap(A[i], A[min]);
            count++;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << A[i];
        if (i < N - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
    cout << count << endl;
}
