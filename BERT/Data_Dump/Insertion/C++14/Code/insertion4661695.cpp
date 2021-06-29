#include <iostream>
using namespace std;

void print_arr(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        if (i > 0) cout << ' ';
        cout << arr[i];
    }
    cout << endl;
}

void insertionSort(int* arr, int len) {
    int val;
    int j;
    print_arr(arr, len);

    for (int i = 1; i < len; i++) {
        val = arr[i];

        // j番目が大きい場合は1つずつずらす
        j = i - 1;
        while (j >= 0 && arr[j] > val) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = val;

        print_arr(arr, len);
    }
}

int main() {
    int N;
    int arr[100];

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    insertionSort(arr, N);
}
