
#include <iostream>

using namespace std;

void print(int A[], int N) {
    for (int k = 0; k < N-1; k++) {
        cout << A[k] << " ";
    }
    cout << A[N-1] << "\n";

}
void selectionSort(int A[], int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        int minj = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (minj != i) {
            swap(A[i], A[minj]);
            count++;
        }

    }
    print(A, N);
    cout << count << "\n";
}
static int A[100];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    selectionSort(A, n);
    return 0;

}
