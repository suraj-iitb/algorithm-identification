#include <iostream>
using namespace std;


void print_arr(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        if (i > 0) cout << ' ';
        cout << arr[i];
    }
    cout << endl;
}

int selectionSort(int* arr, int len) {
    int min;
    int count = 0;

    for (int i = 0; i < len; i++) {
        min = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        if (min != i) {
            swap(arr[min], arr[i]);
            count++;
        }
    }

    return count;
}

int main() {
    int N;
    int arr[100];
    int count;

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    count = selectionSort(arr, N);
    print_arr(arr, N);
    cout << count << endl;
}
