#include <iostream>
using namespace std;
int main() {
    int length = 0;
    cin >> length;
    int* data = new int[length];

    for (int i = 0; i < length; ++i) {
        cin >> data[i];
    }   

    int swap_times = 0;
    for (int i = 0; i < length - 1; ++i) {
        for (int j = 0; j < length - 1; ++j) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
                ++swap_times;
            }   
        }   
    }   
    for (int i = 0; i < length; ++i) {
        if (i < length - 1) {
            cout << data[i] << " ";
        } else {
            cout << data[i] << endl;
        }   
    }   
    cout << swap_times << endl;
}
