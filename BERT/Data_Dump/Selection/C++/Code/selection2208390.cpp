#include <iostream>
#include <algorithm>

using namespace std;

// ?????????????????????????????°?????????
int selectionSort(int *A, int n) {
    int minj, count;
    count = 0;
    for (int i = 0; i < n; i++) {
        minj = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            swap(A[i], A[minj]);
            count++;
        }
    }
    return count;
}

int main(int argc, char const* argv[]) {
    int n;
    cin >> n;
    int A[100];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int count;
    count = selectionSort(A, n);
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
    return 0;
}
