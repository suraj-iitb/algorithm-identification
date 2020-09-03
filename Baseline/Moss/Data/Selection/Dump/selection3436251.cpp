#include <iostream>
using namespace std;

void trace(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i];
        if (i != n - 1) cout << " ";
        else cout << endl;
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int selectionSort(int a[], int n){
    int c = 0;
    for(int i = 0; i < n - 1; i++){
        int minj = i;
        for(int j = i + 1; j < n; j++){
            if(a[minj] > a[j]) minj = j;
        }
        if(minj != i){
            swap(a[i], a[minj]);
            c++;
        }
    }

    return c;
}

int main(void){
    int n, a[100], c;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    c = selectionSort(a, n);
    trace(a, n);
    cout << c << endl;

    return 0;
}

