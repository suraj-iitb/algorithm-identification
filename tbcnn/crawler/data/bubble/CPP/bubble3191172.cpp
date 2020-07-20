#include <iostream>
using namespace std;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int swapCount = 0;

void b_sort(int *array, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j + 1] < array[j]) {
                swapCount++;
                swap(array[j + 1], array[j]);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int array[100] = {0};
    
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    
    b_sort(array, n);
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << array[i];
    }
    cout << endl << swapCount << endl;
    
    
    return 0;
}

