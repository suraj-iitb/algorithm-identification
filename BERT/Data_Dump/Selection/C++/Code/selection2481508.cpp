#include <iostream>
using namespace std;
static const int MAX = 100;

int SelectionSort(int* A, int n) {
    int minj, count = 0;
    for(int i = 0; i < n ; ++i) {
        minj = i;
        for(int j = i; j < n; ++j) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if(i != minj){
            swap(A[i], A[minj]);
            count++;
        }
    }
    return count;
}

int main(int argc, char const *argv[]) {
    int A[MAX];
    int n, count;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    count = SelectionSort(A, n);

    cout << A[0];
    for(int i = 1; i < n; ++i) {
        cout << " " << A[i] << flush;
    }
    cout << endl;
    cout << count << endl;

    return 0;
}
