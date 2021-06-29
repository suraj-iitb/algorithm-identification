#include <iostream>
#define N_MAX 100
using namespace std;

void insertionSort(int a[] , int n) {
    for (int i = 0; i < n; ++i) {
        int tmp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > tmp ){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = tmp;

        for (int k = 0; k < n; ++k){
            if(k > 0) cout << " ";
            cout << a[k];
        }
        cout << endl;

    }
}

int main(){
    int n;
    cin >> n;
    int a[N_MAX];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    insertionSort(a, n);

    return 0;
}
