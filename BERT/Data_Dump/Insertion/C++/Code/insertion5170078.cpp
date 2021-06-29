#include <iostream>
using namespace std;

void printArray(int arr[100], int n);

int main() {
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    printArray(arr, n);
    for (int i = 1; i < n; i++) {
        int curr = arr[i], j = i - 1;

        while (j >= 0 && curr < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = curr;
        cout << endl;
        printArray(arr, n);
        
    }
    cout << endl;
    return 0;

}

void printArray(int arr[100], int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0)
            cout << " ";
        cout << arr[i];
    }
}
