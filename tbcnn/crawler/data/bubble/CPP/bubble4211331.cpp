#include <iostream>
using namespace std;

void bubbleSort(int A[], int N, int &count) {
    int flag = 1;
    int i = 0;
    while (flag) {
        flag = 0;
        for (int j = N - 1; j >= i + 1; --j) {
            if (A[j - 1] > A[j]) {
                int temp = A[j - 1];
                A[j - 1] = A[j];
                A[j] = temp;
                count += 1;
                flag = 1;
            }
        }
        ++i;
    }
}

int main() {
    int N, count = 0;
    int A[100];
    cin >> N;
    for(int i = 0; i < N; ++i) {cin >> A[i];}
    
    bubbleSort(A, N, count);
    for (int i = 0; i < N; ++i) {
        if (i > 0)
            cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
    return 0;
}
