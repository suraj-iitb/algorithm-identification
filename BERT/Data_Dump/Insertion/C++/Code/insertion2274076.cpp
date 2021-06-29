#include <iostream>
using namespace std;

char blank = ' ';
void print_array(int* data, int length) {
    for (int i = 0; i < length; ++i) {
        if (i == length - 1) {
            cout << data[i] << endl;
        } else {
            cout << data[i] << blank;
        }
    }
}

int main() {
    int data_length = 0;
    cin >> data_length;
    int* data = new int[data_length];

    for (int i = 0; i < data_length; ++i) {
        cin >> data[i];
    }

    print_array(data, data_length);

    for (int i = 1; i < data_length; ++i) {
        int k = i;
        int j = i;
        while (j >= 0 && data[j] < data[j - 1]) {
            std::swap(data[j], data[j - 1]);
            --j;
        }
        print_array(data, data_length);
    }


    delete[] data;
    return 0;
}
