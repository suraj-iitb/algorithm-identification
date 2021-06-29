#include <iostream>
using namespace std;
int main(void){
    int n;
    int key, p=0;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) {
        for(int j=n-1;j>i;j--) {
            if(a[j] < a[j-1]) {
                key = a[j-1];
                a[j-1] = a[j];
                a[j] = key;
                p++;
            }
        }
    }
    for(int i=0;i<n;i++) {
        cout << a[i];
        if(i == n-1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
    cout << p << endl;
}
