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

void selection_sort(int A[], int N) {
    int minValue, minIndex, temp, cnt=0;
    for (int i = 0; i < N - 1; i++) {
        minValue = A[i];
        minIndex = i;
        for (int j = i + 1; j < N; j++) {
            if (A[j] < minValue) {
                minValue = A[j];
                minIndex = j;
            }
        }
        if(minIndex != i) {
            temp = A[i];
            A[i] = A[minIndex];
            A[minIndex] = temp;
            cnt++;
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

    selection_sort(array, n);

    return 0;
}
