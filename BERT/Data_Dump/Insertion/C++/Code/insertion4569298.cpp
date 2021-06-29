#include <iostream>

using namespace std;

#define MAX 100

void insertionSort(int a[], int n){
    int v, j;
    for(int i = 0; i < n; i++){
        cout << a[i];
        if(i != n - 1) cout << " ";
    }
    cout << endl;
    for(int i = 1; i < n; i++){
        v = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        for(int i = 0; i < n; i++){
            cout << a[i];
            if(i != n - 1) cout << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    int a[MAX];

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    insertionSort(a, n);

    return 0;
}

