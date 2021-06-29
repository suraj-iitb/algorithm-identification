#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    int num;
    int *arr;

    cin >> num;
    arr = new int[num];
    for(int i = 0; i < num; i++)
        cin >> arr[i];
        
    for(int k = 0; k < num; k++) {
            if(k > 0)
                cout << " ";
            cout << arr[k];
    }
    cout << endl;

    for(int i = 1, j = i - 1; i < num; i++) {
        while(j >= 0 && arr[j] > arr[j+1]) {
            swap(arr[j], arr[j+1]);
            j--;
        }
        
        j = i;
        for(int k = 0; k < num; k++) {
            if(k > 0)
                cout << " ";
            cout << arr[k];
        }
        cout << endl;
    }

    delete [] arr;
    
    return 0;
}
