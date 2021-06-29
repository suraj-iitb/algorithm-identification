#include <iostream>
using namespace std;
     
int main() {
    int len; 
    cin >> len; 
    int arr[len] = {};
    int j, key;
    for(int i = 0; i < len; i++) {
        cin >> arr[i];
    }
    for(int i = 1; i < len; i++) {
        for (int j = 0; j < len; j++) {
            cout << arr[j];
            if (j == len-1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
        key = arr[i];
        j = i-1; 
        while( j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    for (int j = 0; j < len; j++) {
            cout << arr[j];
            if (j == len-1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
}
