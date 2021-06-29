#include <iostream>
#include <algorithm>
using namespace std;
void display(int N, int* arr) {
    for(int i = 0; i < N-1; i++) cout << arr[i] << " ";
    cout << arr[N-1] << endl;
}
void bubbleSort(int N, int* arr) {
    int cnt = 0;
    for(int i = 0; i < N-1; i++) {
        for(int j = N-1; j >= 0; j--) {
            if(arr[j-1] > arr[j]) {
                swap(arr[j-1], arr[j]);
                cnt++;
            }
        }
    }
    display(N, arr);
    cout << cnt << endl;
}
int main(void){
    int N; cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++) cin >> arr[i];
    bubbleSort(N, arr);
}
