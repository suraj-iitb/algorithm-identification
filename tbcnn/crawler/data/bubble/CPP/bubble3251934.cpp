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
        for(int j = n-1; j >= i+1; j--) {
            if(arr[j] < arr[j-1]) {
                int temp = arr[j];
                arr[j] = arr[j-1]; 
                arr[j-1] = temp; 
                count = count + 1; 
            }
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
