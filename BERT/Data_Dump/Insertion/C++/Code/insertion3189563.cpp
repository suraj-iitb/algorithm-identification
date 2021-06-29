#include <iostream>
#include <cstdlib>
using namespace std;

void printArray(int *array, int length) {
    for (int i = 0; i < length; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << array[i];
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int array[100];
    
    int count = 0;
    cin >> count;
    for (int i = 0; i < count; i++) {
        cin >> array[i];
    }
    
    printArray(array, count);
    for (int i = 1; i < count; i++) {
        int current = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > current) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current;
        printArray(array, count);
    }
    
    return 0;
}

