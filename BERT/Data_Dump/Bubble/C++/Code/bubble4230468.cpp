#include <iostream>
using namespace std;

int bubbleSort(int A[], int N) {
    int cnt = 0, flg = 1;
    while (flg) {
        flg = 0;
        for (int j = N - 1; j >= 1; j--) {
            if (A[j] < A[j-1]) {
              swap(A[j], A[j -1]);
              cnt++;
              flg = 1;
            } 
        }
    }
    return cnt;
}

int main() {
    int A[100], N, output;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    output = bubbleSort(A, N);
  
    for (int i = 0; i < N; i++) {
      if(i) cout << " ";
      cout << A[i];
    }
    cout << endl;
    cout << output << endl;  
}
