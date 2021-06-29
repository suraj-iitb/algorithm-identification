#include <iostream>
using namespace std;
#define MAX 100

int selectionSort(int a[], int n){
    int sw = 0;
    for(int i = 0; i < n - 1; i++){
        int minj = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[minj]){
                minj = j;
            }
        }
        if(a[i] > a[minj]){
            swap(a[i], a[minj]);
            sw++;
        }
    }
    return sw;
}

int main(){
    int n;
    cin >> n;
    int a[MAX];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int sw = selectionSort(a, n);
    for(int i = 0; i < n; i++){
        cout << a[i];
        if(i != n-1) cout << " ";
    }
    cout << endl;
    cout << sw << endl;
    return 0;
}

