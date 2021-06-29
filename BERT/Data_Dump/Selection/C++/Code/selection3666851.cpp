#include <iostream>
using namespace std;

int select(int* a, int n) {
    int copy;
    int count = 0;
    int min;
    
    for(int i = 0; i < n; ++i) {
        min = i;
        for(int j = i; j < n; ++j) {
            if(a[j] < a[min]) {
                min = j;
            }
        }
        if(i != min) {
            copy = a[i];
            a[i] = a[min];
            a[min] = copy;
            count++;
        }
    }
    return count;
}
int main(void) {
    int n;
    int a[100];
    int count = 0;

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    count = select(a, n);
    
    cout << a[0];
    for(int i = 1; i < n; ++i) {
        cout << ' ' << a[i];
    }
    cout << endl;
    cout << count << endl;
    
    return 0;
}

