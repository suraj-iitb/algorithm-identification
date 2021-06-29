#include <iostream>
using namespace std;

int selectionSort(int a[], int n) {
    int sw{};
    for(int i = 0; i < n; i++) {
        int minj = i;
        for(int j = i; j < n; j++) {
            if(a[j] < a[minj])
                minj = j;
        }
        swap(a[i], a[minj]);
        if(i != minj)
            sw++;
    }
    return sw;
}

int main() {
    int n, a[100], sw;
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sw = selectionSort(a, n);
    
    for(int i = 0; i < n; i++) {
        if(i) cout << " ";
        cout << a[i];
    }
    cout << "\n" << sw << endl;
    
    return 0;
}
