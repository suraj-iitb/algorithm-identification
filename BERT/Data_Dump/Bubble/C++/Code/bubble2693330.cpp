#include <iostream>
using namespace std;
int num, temp;
int count = 0;

void print(int array[]) {
    for (int i = 0; i < num; i++) {
        if (i == num - 1) {
            cout << array[i] << endl;
        } else {
            cout << array[i] << " ";
        }
    }
}

    int main() {
        cin >> num;
        int array[num] = {};
        for (int i = 0; i < num; i++) {
            cin >> array[i];
        }
        for (int i = 1; i < num; i++) {
            for (int j = 0; j < num - 1; j++) {
                if (array[j] > array[j + 1]) {
                    temp = array[j + 1];
                    array[j+1] = array[j];
                    array[j] = temp;
                    count++;
                }
            }

        }
        print(array);
        cout << count << endl;
        return 0;
    }
