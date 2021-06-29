#include <iostream>
using namespace std;

static const int MAX = 100;

int A[MAX];
int N;

void insertionSort();
void Print();

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    insertionSort();
}


void insertionSort() {
    int v, j;
    Print(); // output
    for (int i = 1; i < N; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 and A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j+1] = v;
        
        Print(); // output

    }
}

void Print() {
    for (int i = 0; i < N; i++) {
        if (i) cout << ' ';
        cout << A[i];
    }
    cout << '\n';
}

