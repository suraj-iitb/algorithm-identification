#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        cout << A[i] << (i < N - 1 ? " " : "\n");
    }
    for (int i = 1; i < N; i++) {
        int v = A[i];
        int j = i - 1;
        while (A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        for (int k = 0; k < N; k++) {
            cout << A[k] << (k < N - 1 ? " " : "\n");
        }
    }
    return 0;
}
