#include <iostream>
using namespace std;
void display(int N, int* arr) {
    for(int i = 1; i < N; i++) cout << arr[i] << " ";
    cout << arr[N] << endl; 
}
void insertionSort(int N, int* arr) {
    display(N, arr);
    for(int i = 2, v; i <= N; i++) {
        v = arr[i];
        for(int j = i-1; j >= 0; j--) {
            if(v >= arr[j]) {
                arr[j+1] = v;
                break;
            }
            arr[j+1] = arr[j];
        }
        display(N, arr);
    }
}
int main(void){
    int N; cin >> N;
    int arr[N+1]; arr[0] = 0;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    insertionSort(N, arr);
}
