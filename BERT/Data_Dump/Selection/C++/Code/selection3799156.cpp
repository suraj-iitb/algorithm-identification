#include <iostream>
#include <algorithm>
using namespace std;
void display(int N, int* arr) {
    for(int i = 0; i < N-1; i++) cout << arr[i] << " ";
    cout << arr[N-1] << endl;
}
void selectionSort(int N, int* arr) {
    int cnt = 0;
    for(int i = 0; i < N-1; i++) {
        int p = N-1;
        for(int j = p; j >= i; j--) {
            if(arr[p] >= arr[j]) p = j;
        }
        if(p == i) continue;
        swap(arr[p], arr[i]);
        cnt++;
    }
    display(N, arr);
    cout << cnt << endl;
}
int main(void){
    int N; cin >> N;
    int arr[N];
    for(int i = 0; i < N; i++) cin >> arr[i];
    selectionSort(N, arr);
}
