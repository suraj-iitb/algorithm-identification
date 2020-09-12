#include <iostream>
using namespace std;

void insertionSort(int a[], int n){
    for(int i = 0; i < n; i++){
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v){
            a[j+ 1 ] = a[j];
            j--;
        }
        a[j + 1] = v;

        for (int i = 0; i < n; i++){
            cout << a[i];
            if (i != n - 1) cout << " ";
            else cout << endl;
        }
    }
}

int main(void){
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    insertionSort(a, n);

    return 0;
}

