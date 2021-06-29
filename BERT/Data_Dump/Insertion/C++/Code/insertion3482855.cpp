#include <iostream>
#include <vector>

using namespace std;

void output_array(vector<int> &arr, int num, bool add_lf) {

    for (int i=0; i<num; i++) {
        cout << arr[i];
        if (i != num-1) {
            cout << " ";
        }
    }

    if (add_lf) {
        cout << endl;
    }
}

void insertion_sort(vector<int> &arr, int num) {

    for (int i = 1; i < num; i++) {
        int v = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > v) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = v;

        output_array(arr, num, true);
    }
}

int main() {

    int num;
    cin >> num;

    vector<int> arr(num);
    for (int i=0; i<num; i++) {
        cin >> arr[i];
    }

    output_array(arr, num, true);

    insertion_sort(arr, num);

    return 0;
}
