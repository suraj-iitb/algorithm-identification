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
        int min = data[i];
        int min_index = i;
        for (int j = i; j < length; ++j) {
            if (data[j] < min) {
                min = data[j];
                min_index = j;
            }   
        }   
        if (min < data[i]) {
            swap(data[min_index], data[i]);
            ++swap_times;
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
