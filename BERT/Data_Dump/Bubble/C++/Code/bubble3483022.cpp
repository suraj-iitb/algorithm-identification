#include <iostream>
#include <vector>

using namespace std;

// 戻り値は交換回数
int bubble_sort(vector<int> &arr, int num) {

    int exchange = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int j = num - 1; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                int v = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = v;
                flag = true;
                exchange++;
            }
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

    int exchange = bubble_sort(arr, num);

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
