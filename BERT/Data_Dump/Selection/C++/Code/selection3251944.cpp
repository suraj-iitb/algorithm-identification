#include <iostream>
using namespace std;

int main() {
    int count = 0;
    int n; 
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    for(int i = 0; i < n; i++) {
        int mini = i;
        for (int j = i; j < n; j++) {
            if(arr[j] < arr[mini]) {
                mini = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[mini];
        arr[mini] = temp;
        if(mini != i) {
            count++;
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << arr[i];
        if(i == n-1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
    
    cout << count << endl;
    
}
