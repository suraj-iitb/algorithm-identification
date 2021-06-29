#include<iostream>
using namespace std;

int bubbleSort(int arr[], int N) {
    int sw=0;
    bool flag=1;
    for (int i=0; flag; i++) {
        flag=0;
        for (int j=N-1; j>=i+1; j--) {
            if (arr[j-1] > arr[j]) {
                swap(arr[j-1], arr[j]);
                flag=1;
                sw++;
            }
        }
    }
    return sw;
}

int main() {
    int arr[100], N, sw;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }
sw=bubbleSort(arr, N);

for (int i=0; i<N; i++) {
    if (i) cout << " ";
    cout << arr[i];
}

cout << "\n";
cout << sw << endl;

return 0;
}
