#include <iostream>
using namespace std;


int bubbleSort(int arr[],int n){
    int count = 0,flag = 1;

    for (int i = 0; flag; ++i) {
        flag = 0;

        for (int j = n - 1; j >= i + 1; --j) {
            if (arr[j] < arr[j - 1]){
                swap(arr[j],arr[j - 1]);
                flag = 1;
                count++;
            }
        }
    }
    return count;
}


int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int res = bubbleSort(arr,n);
    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << arr[i];
    }
    cout << endl;
    cout << res << endl;

    return 0;
}
