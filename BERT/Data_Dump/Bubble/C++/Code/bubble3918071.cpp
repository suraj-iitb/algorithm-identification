#include <iostream>

using namespace std;

void outputArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        if (i == n - 1) {
            cout << arr[i] << endl;
        } else {
            cout << arr[i] << " ";
        }
}

void bubble_sort(int A[], int N) {
    int temp, cnt = 0;
    int flag = 1;
    for (int i = 0; flag; i++) {
        flag = 0;
        for (int j = N - 1; j > i; j--) {
            if (A[j] < A[j - 1]) {
                temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
                flag = 1;
                cnt++;
            }
        }
    }

    outputArray(A, N);
    cout << cnt << endl;
}

int main() {
    int n;
    int array[100];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> array[i];

    bubble_sort(array, n);

    return 0;
}
