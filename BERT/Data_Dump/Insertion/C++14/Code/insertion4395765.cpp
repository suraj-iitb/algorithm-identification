#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> array(n);

    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            cout << array[i];
        } else {
            cout << " " << array[i];
        }
    }
    cout << endl;

    for (int i = 1; i < n; ++i) {
        int var = array[i];
        int j = i - 1;
        for (; j >= 0 && array[j] > var ; --j) {
            array[j + 1] = array[j];
        }

        array[j + 1] = var;

        for (int k = 0; k < n; ++k) {
            if (k == 0) {
                cout << array[k];
            } else {
                cout << " " << + array[k];
            }
        }
        cout << endl;
    }
}

