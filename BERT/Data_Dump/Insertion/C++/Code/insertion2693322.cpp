#include <iostream>
using namespace std;

int main() {
    int num, scan, key, j;
    cin >> num;
    int array[num] = {};
    for(int i = 0; i < num; i++) {
        cin >> scan;
        array[i] = scan;

    }
    for (int i = 0; i < num; i++) {
        if (i == num - 1) {
            cout << array[i] << endl;
        } else {
            cout << array[i] << " ";
        }
    }
    for(int i = 1; i < num; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j +1] = array[j];
            j--;
        }
        array[j +1] = key;
        for (int i = 0; i < num; i++) {
            if (i == num - 1) {
                cout << array[i] << endl;
            } else {
                cout << array[i] << " ";
            }
        }
    }
    return 0;
}
