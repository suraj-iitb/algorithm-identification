#include <iostream>
using namespace std;
int main(void){
    // Here your code !
    int n, key, j;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    for(int i=0;i<n;i++) {
        key = a[i];
        j = i-1;
        while(j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
        for (int k=0;k<n;k++) {
            cout << a[k];
            if(k!=n-1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }
}
