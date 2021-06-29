#include <iostream>
#include <array>
using namespace std;
int N, A[1000];

void print() {
    cout << A[0];
    for (int i = 1; i < N; i++) {
        cout << " " << A[i];
    }
    cout << endl;
}

void insertion_sort() {
    print();
    for (int i = 1; i < N; i++) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        print();
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    insertion_sort();
    return 0;
}
