#include <iostream>
#include <algorithm>
using namespace std;
#include <cmath>

void trace(int A[], int n){
    for (int i = 0; i < n-1; i++) cout << A[i] << " ";
    cout << A[n-1] << "\n";
}

int main() {
    int N, flag = 1, temp, count = 0;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) cin >> A[i];

    while (flag){
        flag = 0;
        for (int i = N-1; i > 0; i--){
            if (A[i] < A[i-1]){
                temp = A[i];
                A[i] = A[i-1];
                A[i-1] = temp;
                count++;
                flag = 1;
            }
        }
    }
    trace(A,N);
    cout << count << endl;

    return 0;
}
