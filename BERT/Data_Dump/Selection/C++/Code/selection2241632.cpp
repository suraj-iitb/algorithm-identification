#include <iostream>
using namespace std;
int main(void){
    int n;
    int key, p=0;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    int min;
    for(int i=0;i<n;i++) {
        min = i;
        for(int j=i;j<n;j++) {
            if(a[j] < a[min]) min = j;
        }
        if(i != min) {
            key = a[min];
            a[min] = a[i];
            a[i] = key;
            p++;
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
