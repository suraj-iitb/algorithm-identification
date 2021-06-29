#include <iostream>
using namespace std;

void print(int a[], int n) {
    for (int i = 0; i < n; i++) {
    cout << a[i];
    if (i < n - 1) {
        cout << ' ';
    }
    else  {
        cout << endl;
    }
}
}

int main(void){
    // Your code here!
    int n;
    cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++) { cin >> a[i]; }
    
    for (int i = 1; i < n; i++) {
        print(a, n);

        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
    }
    
    print(a, n);
}

