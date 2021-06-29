#include <iostream>
#include <vector>

using namespace std;

// 戻り値は交換回数
int selection_sort(vector<int> &arr, int num) {
    int exchange = 0;
    for (int i = 0; i < num; i++) {
        int min_j = i;
        for (int j = i; j < num; j++) {
            if (arr[j] < arr[min_j]) {
                min_j = j;
            }
        }
        if (min_j != i) {
            int v = arr[i];
            arr[i] = arr[min_j];
            arr[min_j] = v;
            exchange++;
        }
    }
    return exchange;
}

int main() {

    int num;
    cin >> num;

    vector<int> arr(num);
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    int exchange = selection_sort(arr, num);

    for (int i = 0; i < num; i++) {
        cout << arr[i];
        if (i != num - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
    cout << exchange << endl;

    return 0;
}

