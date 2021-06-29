#include <iostream>

using namespace std;


void print_arr(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        if (i > 0) cout << ' ';
        cout << arr[i];
    }
    cout << endl;
}

void swap(int* arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int bubbleSort(int* arr, int len) {
    int count = 0;
    int flag = 1;       // 比較対象が存在するフラグ

    while (flag) {
        flag = 0;

        for (int i = len - 1; i >= 1; i--) {
            if (arr[i] < arr[i - 1]) {
                swap(arr, i, i - 1);
                count++;
                flag = 1;
            }
        }
    }

    return count;
}

int main() {
    int N;
    int count;
    int arr[100];

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    count = bubbleSort(arr, N);
    print_arr(arr, N);
    cout << count << endl;
}
