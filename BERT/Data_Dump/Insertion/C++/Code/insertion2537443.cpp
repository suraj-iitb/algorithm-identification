#include<iostream>
using namespace std;
int main() {
    int arr[1000], num, i, j, k, v;
    cin>>num;
    for (i = 0; i < num; i++) {
        cin>>arr[i];
    }
    for (k = 0; k < num; k++) {
        cout<<arr[k];
        if (k != num - 1) {
            cout<<" ";
        }
    }
    cout<<endl;
    for (i = 1; i < num; i++) {
        v = arr[i];
        j = i - 1;
        while (j >= 0 && v < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = v;
        for (k = 0; k < num; k++) {
            cout<<arr[k];
            if (k != num - 1) {
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
