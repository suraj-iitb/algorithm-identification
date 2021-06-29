

#include <iostream>

using namespace std;

void print(int A[], int N) {
    for (int k = 0; k < N-1; k++) {
        cout << A[k] << " ";
    }
    cout << A[N-1] << "\n";

}
void bubbleSort(int A[], int N) {
    int flag = true;
    int count = 0, i=0;
    while (flag) {
        flag = false;
        for (int j = N-1; j >= i + 1; j--) {
            if (A[j] < A[j - 1]) {
                int tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                count++;
                flag = true;
            }
        }
        i++;
    }
    print(A, N);
    cout << count << "\n";
}
static int A[100];
int main() {
    int n;
    cin >> n;
    //int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    //print(A);
    bubbleSort(A, n);
    return 0;

}


