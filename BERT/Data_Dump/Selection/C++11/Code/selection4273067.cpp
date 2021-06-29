#include <iostream>
using namespace std;

int swapCount;

// N 個の要素を含む 0-オリジンの配列 A
void selectionSort(int a[], int n){
    for(int i=0; i<n; i++){
        int minj = i;
        for(int j=i; j<n; j++){
            if(a[j] < a[minj]){
                minj = j;
            }
        }
        if(i != minj){
            swap(a[i], a[minj]);
            swapCount++;
        }
    }
}

void print(int a[], int n){
    for(int i=0; i<n-1; i++){
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
}

int main(void){
    int n;
    cin >> n;
    int a[110];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    swapCount = 0;
    selectionSort(a, n);

    print(a, n);

    cout << swapCount << endl;
    return 0;
}
