#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n + 1];
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    for(int i = 1; i <= n; ++i){
        arr[0] = arr[i];
        int j = i-1;
        while(arr[0] < arr[j]) { arr[j + 1] = arr[j]; --j; }
        arr[j + 1] = arr[0];
        for(j = 1; j < n; ++j) cout << arr[j] << " ";
        cout << arr[j] << endl;
    }
    return 0;
}
