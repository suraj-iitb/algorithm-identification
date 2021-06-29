#include <bits/stdc++.h>
using namespace std;

void print(int *arr, int len){
    for(int k = 0; k < len - 1; k++){
            cout << arr[k] << " ";
        }
}

int main(){
    int len;
    int arr[100];
    cin >> len;
    for(int i = 0; i < len; i++){
        cin >> arr[i];
    }
    int temp, j;
    for(int i = 1; i < len; i++){
        print(arr, len);
        cout << arr[len - 1] << endl;
        temp = arr[i];
        for(j = i - 1; j >= 0 && arr[j] > temp; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }
    print(arr, len);
    cout << arr[len - 1] << endl;
}
