#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> A, int N);

int main() {
    
    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i=0; i<N; i++) {
        cin >> A.at(i);
    }
    
    selectionSort(A, N);
    
    return 0;
}

void selectionSort(vector<int> A, int N) {
    int count = 0;
    for (int i=0; i<N; i++) {
        int minj = i;
        for (int j = i; j < N; j++) {
            if (A.at(j) < A.at(minj)) {
                minj = j;
            }
        }
        if (i != minj) {
            int tmp = A.at(i);
            A.at(i) = A.at(minj);
            A.at(minj) = tmp;
            count++;
        }
    }
    for (int i=0; i<N; i++) {
        cout << A.at(i);
        if ( i == N-1) {
            cout << endl;
        } else {
            cout << ' ';
        }
    }
    cout << count << endl;
}

