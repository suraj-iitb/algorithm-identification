#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for( int i=0; i<n; i++ ){
        cin >> arr[i];
    }
    for( int j=1; j<n; j++ ){
        cout << arr[0];
        for( int i=1; i<n; i++ ){
            cout << " " << arr[i];
        }
        cout << endl;
        int key = arr[j];
        int i = j-1;
        while( i>=0 && arr[i]>key ){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
    cout << arr[0];
    for( int i=1; i<n; i++ ){
        cout << " " << arr[i];
    }
    cout << endl;
    return 0;
}
